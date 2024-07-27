/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:29:22 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:25:12 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_color(char *buff, int endian, int color, int trans)
{
	if (endian == 1)
	{
		buff[0] = trans;
		buff[1] = (color >> 16) & 0xFF;
		buff[2] = (color >> 8) & 0xFF;
		buff[3] = (color) & 0xFF;
	}
	else
	{
		buff[0] = (color) & 0xFF;
		buff[1] = (color >> 8) & 0xFF;
		buff[2] = (color >> 16) & 0xFF;
		buff[3] = trans;
	}
}

int	put_pix(t_fdf *fdf, t_dot pix)
{
	int	pixel;

	if (pix.ax[0] >= WIN_WIDTH || pix.ax[1] >= WIN_HEIGHT
		|| pix.ax[0] < 0 || pix.ax[1] < 0)
		return (-1);
	pixel = ((int)pix.ax[1] * fdf->b_map.lines) + ((int)pix.ax[0] * 4);
	if (fdf->b_map.bpix != 32)
		pix.color = mlx_get_color_value(fdf->set.mlx, pix.color);
	set_color(&fdf->b_map.buffer[pixel], fdf->b_map.endi, pix.color, 0);
	return (0);
}

void	dot_aux(t_fdf *fdf, t_dot pixel, t_dot dot, int ref)
{
	int	pos;

	pos = dot.ax[0];
	while (pos <= dot.ax[0] + ref)
	{
		pixel.ax[0] = pos;
		pixel.ax[1] = (int)dot.ax[1] + ref;
		put_pix(fdf, pixel);
		pixel.ax[0] = pos;
		pixel.ax[1] = (int)dot.ax[1] - ref;
		put_pix(fdf, pixel);
		pos++;
	}
}

void	drawing_dot(t_fdf *fdf, t_dot dot, int rad)
{
	int		is_raderr;
	int		ax[2];
	int		mod[2];
	t_dot	pixel;

	ax[0] = rad;
	ax[1] = 0;
	mod[0] = 1 - (rad << 1);
	mod[1] = 0;
	is_raderr = 0;
	pixel.color = dot.color;
	while (ax[0] >= ax[1])
	{
		dot_aux(fdf, pixel, dot, ax[1]);
		dot_aux(fdf, pixel, dot, ax[0]);
		ax[1]++;
		is_raderr += mod[1];
		mod[1] += 2;
		if (((is_raderr << 1) + mod[0]) > 0)
		{
			ax[0]--;
			is_raderr += mod[0];
			mod[0] += 2;
		}
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
