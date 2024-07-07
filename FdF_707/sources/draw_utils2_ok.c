/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:29:22 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 16:30:54 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int	inter_color(int startCo, int endCo, int length, int pix)
{
	int		newCo[3];
	double	inc[3];

	inc[0] = (double)((endCo >> 16) - (startCo >> 16)) / (double)length;
	inc[1] = (double)(((endCo >> 8) & 0xFF)
		- ((startCo >> 8) & 0xFF)) / (double)length;
	inc[2] = (double)((endCo & 0xFF) - (startCo & 0xFF)) / (double)length;

	newCo[0] = (startCo >> 16) + to_round(pix * inc[0]);
	newCo[1] = ((startCo >> 8) & 0xFF) + to_round(pix * inc[1]);
	newCo[2] = (startCo & 0xFF) + to_round(pix * inc[2]);

	return ((newCo[0] << 16) + (newCo[1] << 8) + newCo[2]);
}

void	dot_to_paint(t_dot *dots, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		if (dots[pos].ax[2] < 0)
			dots[pos].is_paint = 0;
		dots[pos].is_paint = 1;
	}
}

int	dot_to_line(t_fdf *fdf, t_dot start, t_dot end)
{
	int		pixels;
	int		length;
	t_dot	discr;
	t_dot	pix;

	if (is_valid_pix(start) == 0 && is_valid_pix(end)== 0)
		return (0);
	discr.ax[0] = end.ax[0] - start.ax[0];
	discr.ax[1] = end.ax[1] - start.ax[1];
	pixels = sqrt((discr.ax[0] * discr.ax[0])
			   + (discr.ax[1] * discr.ax[1]));
	length = pixels;

	discr.ax[0] /= pixels;
	discr.ax[1] /= pixels;

	pix.ax[0] = start.ax[0];
	pix.ax[1] = start.ax[1];

	//color.start_color = start.color;
	//color.end_color = end.color;
	while (pixels > 0)
	{
		pix.color = inter_color(start.color,
						  end.color, length, (length - pixels));
		put_pix(fdf, pix);
		pix.ax[0] += discr.ax[0];
		pix.ax[1] += discr.ax[1];
		pixels--;
	}
	return (1);
}
