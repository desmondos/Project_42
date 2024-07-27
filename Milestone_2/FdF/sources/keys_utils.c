/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:31 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:26:16 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	angle(float *angle, float value)
{
	(*angle) += value;
	if ((*angle) < 0)
		(*angle) += 360;
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

void	control_colorscheme(int keycode, t_map *map)
{
	map->colors.botco = AZUL;
	map->colors.backco = CARBON;
	map->colors.groundco = SAFFRON;
	map->colors.topco = BRICK_RED;
	if (keycode == K_2)
	{
		map->colors.botco = CARBON;
		map->colors.backco = WHITE;
		map->colors.groundco = CARBON;
		map->colors.topco = CARBON;
	}
	if (keycode == K_3)
	{
		map->colors.topco = WHITE;
		map->colors.botco = WHITE;
		map->colors.groundco = WHITE;
	}
	if (keycode == K_4)
	{
		map->colors.topco = ROJO;
		map->colors.botco = SUPERAZUL;
		map->colors.groundco = VERDE;
	}
	do_color(map);
}

int	altitude(int keycode, t_fdf *fdf)
{
	if (keycode == K_9)
		fdf->map.alt += ALTITUDE;
	else if (keycode == K_7)
		fdf->map.alt -= ALTITUDE;
	return (0);
}
