/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:16:55 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bi_free(void **str)
{
	void	**stash;

	if (str)
	{
		stash = str;
		while (*stash)
		{
			free(*stash);
			*stash = NULL;
			stash++;
		}
		free(str);
	}
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	to_clean(t_fdf *fdf)
{
	if (fdf->b_map.img != NULL)
	{
		mlx_destroy_image(fdf->set.mlx, fdf->b_map.img);
		fdf->b_map.img = NULL;
	}
	if (fdf->set.win != NULL)
	{
		mlx_destroy_window(fdf->set.mlx, fdf->set.win);
		fdf->set.win = NULL;
	}
	mlx_destroy_display(fdf->set.mlx);
	free(fdf->set.mlx);
	clean_up(fdf);
}

void	clean_up(t_fdf *fdf)
{
	if (fdf->map.dots)
	{
		free(fdf->map.dots);
		fdf->map.dots = NULL;
	}
	if (fdf->b_map.img)
	{
		mlx_destroy_image(fdf->set.mlx, fdf->b_map.img);
		fdf->b_map.img = NULL;
	}
	if (fdf->set.win)
	{
		mlx_destroy_window(fdf->set.mlx, fdf->set.win);
		fdf->set.win = NULL;
	}
	if (fdf->set.mlx)
	{
		mlx_destroy_display(fdf->set.mlx);
		free(fdf->set.mlx);
		fdf->set.mlx = NULL;
	}
}

int	check_imp_dots(t_fdf *fdf, int index)
{
	if (!is_valid_dot(&fdf->splits[fdf->pos][0]))
		return (free_split(fdf->splits), puterror("inv dot"), 1);
	if (index >= fdf->map.length)
		return (1);
	return (0);
}
