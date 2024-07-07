/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_ok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:10 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 14:54:52 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void	moves(t_dot *dots, t_dot move, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		dots[pos].ax[0] = dots[pos].ax[0] + move.ax[0];
		dots[pos].ax[1] = dots[pos].ax[1] + move.ax[1];
		dots[pos].ax[2] = dots[pos].ax[2] + move.ax[2];
		pos++;
	}
}

void	scales(t_dot *dots, int scale, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		dots[pos].ax[0] = dots[pos].ax[0] * scale;
		dots[pos].ax[1] = dots[pos].ax[1] * scale;
		dots[pos].ax[2] = dots[pos].ax[2] * scale;
		pos++;
	}
}

void	to_isometric(t_map *map)
{
	map->is_geom = 0;
	map->brange = 0;
	map->angle[0] = 30;
	map->angle[1] = 330;
	map->angle[2] = 30;
	map->from.ax[0] = (WIN_WIDTH / 2);
	map->from.ax[1] = (WIN_HEIGHT / 2);
}

void	to_profil(t_map *map)
{
	map->is_geom = 0;
	map->brange = 0;
	map->angle[0] = 90;
	map->angle[1] = 0;
	map->angle[2] = 0;
	map->from.ax[0] = (WIN_WIDTH / 2);
	map->from.ax[1] = (WIN_HEIGHT / 2);
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

void	to_sphere(t_map *map, t_dot *dots)
{
	int	pos;

	pos = 0;
	while (pos < map->length)
	{
		dots[pos].ax[0] = (map->rad + dots[pos].ax[2])
			* cos(dots[pos].pol[LONG]) * sin(dots[pos].pol[LAT]);
		dots[pos].ax[1] = (map->rad + dots[pos].ax[2])
			* sin(dots[pos].pol[LONG]) * sin(dots[pos].pol[LAT]);
		dots[pos].ax[2] = (map->rad + dots[pos].ax[2])
			* cos(dots[pos].pol[LAT]);
		pos++;
	}
}

void	to_pol(t_map *map)
{
	int		pos;
	float	x_moves;
	float	y_moves;

	x_moves = (M_PI * 2) / (map->lim.ax[0] - 1);
	y_moves = (M_PI / (map->lim.ax[1]));
	map->rad = map->lim.ax[0] / (M_PI * 2);
	pos = 0;
	while (pos < map->length)
	{
		map->dots[pos].pol[LONG] = -(map->dots[pos].ax[0]) * x_moves;
		if (map->dots[pos].ax[1] > 0)
			map->dots[pos].pol[LAT] = ((map->dots[pos].ax[1])
				+ (map->lim.ax[1] / 2)) * y_moves - 0.5 * y_moves;
		map->dots[pos].pol[LAT] = (map->dots[pos].ax[1]
			+ (map->lim.ax[1] / 2) - 1) * y_moves + 0.5 * y_moves;
		pos++;
	}
}
