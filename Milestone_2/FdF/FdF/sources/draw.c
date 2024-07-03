/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:29:22 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 15:07:24 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pixel_put_antialiasing(t_set *set, int x, int y, int color)
{
	int	red;
	int	green;
	int	blue;
	int	new_color;

	red = ((color & 0xFF0000) >> 16) * set->brightness;
	green = ((color & 0x00FF00) >> 8) * set->brightness;
	blue = (color & 0x0000FF) * set->brightness;
	new_color = ((red << 16) | (green << 8) | blue);
	pixel_put(set, x, y, new_color);
}

void	pixel_put(t_set *set, int x, int y, int color)
{
	char	*pix;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pix = set->addr + (y * set->len + x * (set->bpp / 8));
		*(int *)pix = color;
	}
}

void	draw_line(t_set *set, t_finp start, t_finp end)
{
	int		pos;
	t_calc	calc;

	pos = 0;
	calculate(&calc, start, end);
	all_rot(set, &start, &end);
	calculate(&calc, start, end);
	while (pos < calc.move)
	{
		pixel_put_antialiasing(set, -calc.x + WIN_WIDTH / 2
			+ set->x_translation, -calc.y + WIN_HEIGHT / 2
			+ set->y_translation, set->color);
		calc.x += calc.diff.dx;
		calc.y += calc.diff.dy;
		pos++;
	}
}

void	display_background(t_set *set)
{
	int	height;
	int	width;

	height = 0;
	while (height <= WIN_HEIGHT)
	{
		width = 0;
		while (width <= WIN_WIDTH)
		{
			pixel_put_antialiasing(set, width, height, set->bg);
			width++;
		}
		height++;
	}
}
