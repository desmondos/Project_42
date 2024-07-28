/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_set_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:05:42 by candriam          #+#    #+#             */
/*   Updated: 2024/07/28 11:41:42 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

	/* Initialise une matrice 3x3 avec des zeros. */

void	initialize_matrix(float matrix[3][3])
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			matrix[row][col] = 0;
			col++;
		}
		row++;
	}
}

	/* Divise la composante z de chaque point par un diviseur */

void	divide_z_coordinate(t_dot *dots, float divisor, int nbr_of_dots)
{
	int	pos;

	pos = 0;
	while (pos < nbr_of_dots)
	{
		dots[pos].ax[2] = dots[pos].ax[2] / divisor;
		pos++;
	}
}

	/* Applique une nouvelle valeur z a chaque point */

void	apply_new_z(t_dot *dots, int length, float range)
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

	/* Libere les ressources allouees et quitte le programme */

int	exit_program(t_fdf *fdf)
{
	free(fdf->maps);
	mlx_destroy_image(fdf->set.mlx, fdf->bg_map.img);
	mlx_destroy_window(fdf->set.mlx, fdf->set.win);
	mlx_destroy_display(fdf->set.mlx);
	free(fdf->map.dots);
	free(fdf->set.mlx);
	exit(0);
}

	/* Affiche un message d'erreur et quitte le programme */

void	terminate_with_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
