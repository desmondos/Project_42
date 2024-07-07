/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_ok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:20:30 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 14:43:49 by candriam         ###   ########.mg       */
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
	buff[0] = (color) & 0xFF;
	buff[1] = (color >> 8) & 0xFF;
	buff[2] = (color >> 16) & 0xFF;
	buff[3] = trans;
}

int	put_pix(t_fdf *fdf, t_dot pix)
{
	int	pixel;
	int	trans;

	trans = 0;
	if (pix.ax[0] >= WIN_WIDTH || pix.ax[1] >= WIN_HEIGHT
		|| pix.ax[0] < 0 || pix.ax[1] < 0)
		return (-1);
	pixel = ((int)pix.ax[1] * WIN_WIDTH * 4) + ((int)pix.ax[0] * 4);
	if (fdf->b_map.bpix != 32)
		pix.color = mlx_get_color_value(fdf->set.mlx, pix.color);
	set_color(&fdf->b_map.buffer[pixel], fdf->b_map.endi, pix.color, trans);
	return (0);
}

int	get_color(t_fdf *fdf, int color)
{
	if (fdf->b_map.bpix != 32)
		color = mlx_get_color_value(fdf->set.mlx, color);
	return (color);
}

void	set_background(t_fdf *fdf, int bg_color)
{
	int	ax[2];
	int	pix;
	int	color;

	ax[0] = 0;
	ax[1] = 0;
	bg_color = get_color(fdf, bg_color);
	while (ax[1] < WIN_HEIGHT)
	{
		while (ax[0] < WIN_WIDTH)
		{
			color = bg_color;
			pix = (ax[1] * fdf->b_map.lines) + (ax[0] * 4);
			set_color(&fdf->b_map.buffer[pix], fdf->b_map.endi, color, 1);
			ax[0]++;
		}
		ax[1]++;
		ax[0] = 0;
	}
}
