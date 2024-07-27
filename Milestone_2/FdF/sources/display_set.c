/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:25:00 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	corres_screen(t_fdf *fdf, t_dot *proj)
{
	fdf->map.from.ax[0] = (WIN_WIDTH / 4);
	fdf->map.from.ax[1] = WIN_HEIGHT / 4;
	fdf->map.from.ax[2] = 0;
	fdf->map.scale = 0.1;
	mapcpy(fdf->map.dots, proj, fdf->map.length);
	parsing(fdf, proj);
	while (!(lim_checks(proj, fdf->map.length)))
	{
		fdf->map.from.ax[0] = (WIDTH / 2);
		fdf->map.from.ax[1] = HEIGHT / 2;
		mapcpy(fdf->map.dots, proj, fdf->map.length);
		parsing(fdf, proj);
		fdf->map.scale += 0.1;
	}
}

void	mapcpy(t_dot *from, t_dot *to, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		to[pos] = from[pos];
		pos++;
	}
}

void	parsing(t_fdf *fdf, t_dot *proj)
{
	divide_z(proj, fdf->map.divide_z, fdf->map.length);
	applynew_z(proj, fdf->map.length, fdf->map.brange);
	if (fdf->map.is_geom)
	{
		to_sphere(&fdf->map, proj);
		if (fdf->map.is_shad)
			dot_to_paint(proj, fdf->map.length);
	}
	rotate_on_x(proj, proj, fdf->map.angle[0], fdf->map.length);
	rotate_on_y(proj, proj, fdf->map.angle[1], fdf->map.length);
	rotate_on_z(proj, proj, fdf->map.angle[2], fdf->map.length);
	orto_proj(proj, proj, fdf->map.length);
	scales(proj, fdf->map.scale, fdf->map.length);
	moves(proj, fdf->map.from, fdf->map.length);
}

void	scales(t_dot *dots, int scale, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		dots[pos].ax[0] *= scale;
		dots[pos].ax[1] *= scale;
		dots[pos].ax[2] *= scale;
		pos++;
	}
}

void	moves(t_dot *dots, t_dot move, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		dots[pos].ax[0] += move.ax[0];
		dots[pos].ax[1] += move.ax[1];
		dots[pos].ax[2] += move.ax[2];
		pos++;
	}
}
