/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_set_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:05:42 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:17:56 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_mat(float mat[3][3])
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			mat[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	divide_z(t_dot *dots, float divisor, int dot_nbr)
{
	int	pos;

	pos = 0;
	while (pos < dot_nbr)
	{
		dots[pos].ax[2] = dots[pos].ax[2] / divisor;
		pos++;
	}
}

void	applynew_z(t_dot *dots, int length, float range)
{
	int		pos;
	float	de_value;

	pos = 0;
	while (pos < length)
	{
		de_value = (((dots[pos].ax[0] * dots[pos].ax[0]) * range)
				+ (dots[pos].ax[1] * dots[pos].ax[1]) * range);
		dots[pos].ax[2] = dots[pos].ax[2] - de_value;
		pos++;
	}
}

int	exit_program(t_fdf *fdf)
{
	free(fdf->maps);
	mlx_destroy_image(fdf->set.mlx, fdf->b_map.img);
	mlx_destroy_window(fdf->set.mlx, fdf->set.win);
	mlx_destroy_display(fdf->set.mlx);
	free(fdf->map.dots);
	free(fdf->set.mlx);
	exit(0);
}

void	terminate(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
