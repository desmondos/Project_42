/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:34:31 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 15:18:20 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	is_doted(t_fdf *fdf, t_dot *dots)
{
	int	pos;

	pos = 0;
	while (pos < fdf->map.length)
	{
		if (dots[pos].is_paint)
			drawing_dot(fdf, dots[pos], 1);
		pos++;
	}
}

void	wireframe(t_dot *dot, t_fdf *fdf, int density, int line)
{
	int	pos;
	int	end_x;
	int	end_y;

	pos = 0;
	while (pos < (int)fdf->map.lim.ax[0])
	{
		end_x = pos + density;
		if (end_x >= (int)fdf->map.lim.ax[0])
			end_x = (int)fdf->map.lim.ax[0] - 1;
		end_y = pos + (int)fdf->map.lim.ax[0] * density;
		if (dot[pos].is_paint)
		{
			dot_to_line(fdf, dot[pos], dot[end_x]);
			if (line + density < (int)fdf->map.lim.ax[1])
				dot_to_line(fdf, dot[pos], dot[end_y]);
		}
		pos += density;
	}
}

void	wired(t_fdf *fdf, t_dot *wire)
{
	int	pos;
	int	density;

	density = 8 / fdf->map.scale;
	if (density == 0)
		density = 1;
	pos = 0;
	while (pos < fdf->map.length)
	{
		wireframe(&wire[pos], fdf, density, (pos / fdf->map.lim.ax[0]));
		pos += (fdf->map.lim.ax[0] * density);
	}
}

void	do_color(t_map *map)
{
	int	pos;

	pos = 0;
	while (pos < map->length)
	{
		import_color((int)map->lim.ax[2], map->min_z,
			   &map->dots[pos], map->colors);
		pos++;
	}
}
