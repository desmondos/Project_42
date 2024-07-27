/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:26:10 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_press(int keycode, t_fdf *fdf)
{
	angle_control(keycode, fdf);
	tools_one(keycode, fdf);
	tools_two(keycode, fdf);
	tools_three(keycode, fdf);
	altitude(keycode, fdf);
	if (keycode >= K_1 && keycode == K_4)
		control_colorscheme(keycode, &fdf->map);
	draw_fdf(fdf, 0);
	return (0);
}

int	key_release(int keycode, t_fdf *fdf)
{
	if (keycode == CTRL_R || keycode == CTRL_L)
	{
		fdf->key.leftctrl = 0;
		fdf->key.rightctrl = 0;
	}
	return (0);
}

void	tools_one(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit_program(fdf);
	if (keycode == K_R)
	{
		from_top(&fdf->map);
		draw_fdf(fdf, SIZED);
	}
	if (keycode == K_C)
	{
		fdf->map.from.ax[0] = (WIN_WIDTH / 2);
		fdf->map.from.ax[1] = (WIN_HEIGHT / 2);
	}
	if (keycode == K_P)
	{
		to_profil(&fdf->map);
		draw_fdf(fdf, SIZED);
	}
}

void	tools_two(int keycode, t_fdf *fdf)
{
	if (keycode == K_D)
		fdf->map.is_dots = !fdf->map.is_dots;
	if (keycode == K_F)
		draw_fdf(fdf, SIZED);
	if (keycode == K_G)
		fdf->map.is_geom = !fdf->map.is_geom;
	if (keycode == K_H)
		fdf->map.is_shad = !fdf->map.is_shad;
	if (keycode == K_L)
		fdf->map.is_lines = !fdf->map.is_lines;
	if (keycode == K_X)
		fdf->map.is_suplines = !fdf->map.is_suplines;
	if (keycode == CTRL_L || keycode == CTRL_R)
	{
		fdf->key.leftctrl = 1;
		fdf->key.rightctrl = 1;
	}
}

void	tools_three(int keycode, t_fdf *fdf)
{
	if (keycode == K_B)
		fdf->map.brange -= 0.0001;
	if (keycode == K_V)
		fdf->map.brange += 0.0001;
	if (keycode == K_SUM)
	{
		if (fdf->key.leftctrl || fdf->key.rightctrl)
			fdf->map.scale *= 1.1;
		if (fdf->map.divide_z > 1)
			fdf->map.divide_z -= 0.1;
	}
	if (keycode == K_MIN)
	{
		if (fdf->key.leftctrl || fdf->key.rightctrl)
			fdf->map.scale /= 1.1;
		fdf->map.divide_z += 0.1;
	}
	if (keycode == K_I)
	{
		to_isometric(&fdf->map);
		draw_fdf(fdf, SIZED);
	}
}
