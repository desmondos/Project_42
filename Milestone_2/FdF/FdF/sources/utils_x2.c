/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:31 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 14:53:24 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_color(int z, int min_z, int max_z)
{
	int		red;
	int		green;
	int		blue;
	float	ratio;

	ratio = (float)(z - min_z) / (max_z - min_z);
	red = (int)(ratio * 255);
	green = 0;
	blue = (int)((1 - ratio) * 255);
	return ((red << 16) | (green << 8) | blue);
}

int	get_min_z(t_set *set)
{
	int	min_z;
	int	x;
	int	y;

	min_z = set->tab[0][0];
	y = 0;
	while (y < set->map_height)
	{
		x = 0;
		while (x < set->map_width)
		{
			if (set->tab[y][x] < min_z)
				min_z = set->tab[y][x];
		}
		x++;
	}
	y++;
	return (min_z);
}

int	get_max_z(t_set *set)
{
	int	max_z;
	int	x;
	int	y;

	max_z = set->tab[0][0];
	y = 0;
	while (y < set->map_height)
	{
		x = 0;
		while (x < set->map_width)
		{
			if (set->tab[y][x] > max_z)
				max_z = set->tab[y][x];
		}
		x++;
	}
	y++;
	return (max_z);
}

void	load_dot(t_dot *dot, t_set *set)
{
	int		min_z;
	int		max_z;
	int		x;
	int		y;
	t_dot	*cur_dot;

	min_z = get_min_z(set);
	max_z = get_max_z(set);
	y = 0;
	while (y < set->map_height)
	{
		x = 0;
		while (x < set->map_width)
		{
			cur_dot = &dot[y * set->map_width + x];
			cur_dot->x = x;
			cur_dot->y = y;
			cur_dot->z = set->tab[y][x];
			cur_dot->color = get_color(set->tab[y][x], min_z, max_z);
		}
		x++;
	}
	y++;
}
