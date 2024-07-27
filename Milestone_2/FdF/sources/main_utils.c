/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:26:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/27 10:00:21 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_init(t_fdf *fdf, int ac, char *filename)
{
	if (ac != 2)
		return (puterror("usage: ./fdf <map.fdf or filepath>"), 1);
	if (!is_fdf_ext(filename))
		return (puterror("wrong or missing fdf extension"), 1);
	if (is_fdf_file(filename) == 1)
		return (ft_printf("No file %s\n", filename), 1);
	if (count_dots(fdf, filename) == 1)
		return (puterror("Found wrong line length. Exiting."), 1);
	return (0);
}

int	is_fdf_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

void	main_init(t_fdf *fdf)
{
	init_var(fdf);
	init_mlx(fdf);
	init_mlx_utils(fdf);
	free_var(fdf);
}

void	free_var(t_fdf *fdf)
{
	if (fdf->map.dots)
	{
		free(fdf->map.dots);
		fdf->map.dots = NULL;
	}
}

void	all_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->set.win, key_press, fdf);
	mlx_hook(fdf->set.win, 2, 1L << 0, key_press, fdf);
	mlx_hook(fdf->set.win, 3, 0, key_release, fdf);
	mlx_hook(fdf->set.win, 4, 1L << 2, mouse_press, fdf);
	mlx_hook(fdf->set.win, 5, 1L << 3, mouse_release, fdf);
	mlx_hook(fdf->set.win, 6, 1L << 6, mouse_drag, fdf);
	mlx_hook(fdf->set.win, 17, 0, exit_program, fdf);
}
