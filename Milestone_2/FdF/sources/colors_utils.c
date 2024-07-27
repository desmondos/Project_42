/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:20:30 by candriam          #+#    #+#             */
/*   Updated: 2024/07/27 09:46:25 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	to_round(double value)
{
	if (value < 0)
		return ((int)(value - 0.5));
	return ((int)(value + 0.5));
}

int	inter_color(int start_co, int end_co, int length, int pix)
{
	int		new_co[3];
	double	inc[3];

	inc[0] = (double)((end_co >> 16) - (start_co >> 16)) / (double)length;
	inc[1] = (double)(((end_co >> 8) & 0xFF)
			- ((start_co >> 8) & 0xFF)) / (double)length;
	inc[2] = (double)((end_co & 0xFF) - (start_co & 0xFF)) / (double)length;
	new_co[0] = (start_co >> 16) + to_round(pix * inc[0]);
	new_co[1] = ((start_co >> 8) & 0xFF) + to_round(pix * inc[1]);
	new_co[2] = (start_co & 0xFF) + to_round(pix * inc[2]);
	return ((new_co[0] << 16) + (new_co[1] << 8) + new_co[2]);
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
