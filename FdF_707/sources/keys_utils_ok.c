/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils_ok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:31 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 16:32:34 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	tools_one(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit_program(fdf);
	if (keycode == K_R)
	{
		_init_map(&fdf->map, 0);
		fdf->map.prop = fdf->map.lim.ax[2] / fdf->map.lim.ax[0];
		if (fdf->map.prop > 0.5)
			fdf->map.divide_z = fdf->map.prop * 30;
		do_color(&fdf->map);
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
	{
		if (fdf->key.leftctrl || fdf->key.rightctrl)
			fdf->map.brange -= 0.0001;
		fdf->map.brange += 0.0001;
	}
	/*if (keycode == K_SUM)
	{
		if (fdf->key.leftctrl || fdf->key.rightctrl)
			fdf->map.scale *= 1.1;
		if (fdf->map.divide_z > 1)
			fdf->map.divide_z -= 10;
	}
	if (keycode == K_MIN)
	{
		if (fdf->key.leftctrl || fdf->key.rightctrl)
			fdf->map.scale /= 1.1;
		else
			fdf->map.divide_z += 10;
	}*/
	if (keycode == K_I)
	{
		to_isometric(&fdf->map);
		draw_fdf(fdf, SIZED);
	}
}

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

void	angle(float *angle, float value)
{
	(*angle) += value;
	if ((*angle) < 0)
		(*angle) = 360 + (*angle);
	if ((*angle) >= 360)
		(*angle) -= 360;
}

void	angle_control(int keycode, t_fdf *fdf)
{
	int	ang;

	ang = 1;
	if (fdf->key.leftctrl || fdf->key.rightctrl)
		ang = 90;
	if (keycode == UP)
		angle(&fdf->map.angle[0], -ang);
	if (keycode == DOWN)
		angle(&fdf->map.angle[0], ang);
	if (keycode == LEFT)
		angle(&fdf->map.angle[1], ang);
	if (keycode == RIGHT)
		angle(&fdf->map.angle[1], -ang);
	if (keycode == K_Q)
		angle(&fdf->map.angle[2], ang);
	if (keycode == K_W)
		angle(&fdf->map.angle[2], -ang);
}

int	exit_program(t_fdf *fdf)
{
	mlx_destroy_window(fdf->set.mlx, fdf->set.win);
	free(fdf->map.dots);
	exit(0);
}

void	terminate(char *str)
{
	if (!str)
		ft_putendl_fd(str, 2);
	perror(str);
	exit(1);
}

void	control_colorscheme(int keycode, t_map *map)
{
	map->colors.botCo = AZUL;
	map->colors.backCo = CARBON;
	map->colors.groundCo = SAFFRON;
	map->colors.topCo = BRICK_RED;
	if (keycode == K_2)
	{
		map->colors.botCo = CARBON;
		map->colors.backCo = WHITE;
		map->colors.groundCo = CARBON;
		map->colors.topCo = CARBON;
	}
	if (keycode == K_3)
	{
		map->colors.topCo = WHITE;
		map->colors.botCo = WHITE;
		map->colors.groundCo = WHITE;
	}
	if (keycode == K_4)
	{
		map->colors.topCo = ROJO;
		map->colors.botCo = SUPERAZUL;
		map->colors.groundCo = VERDE;
	}
	do_color(map);
}

int	altitude(int keycode, t_fdf *fdf)
{
	if (keycode == K_SUM)
		fdf->map.alt += ALTITUDE;
	else if (keycode == K_MIN)
		fdf->map.alt -= ALTITUDE;
	return (0);
}

int	mouse_zoom(int mousecode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
	{
		while (fdf->map.scale > -MAX_ZOOM)
		{
			fdf->map.scale *= ZOOM_FACTOR;
			break ;
		}
	}
	else if (mousecode == 5 && fdf->map.scale < -MIN_ZOOM)
		fdf->map.scale /= ZOOM_FACTOR;
	return (0);
}
