/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:31 by candriam          #+#    #+#             */
/*   Updated: 2024/07/29 08:32:30 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

	/* Modifie l'angle en fonction de la valeur donnee */

void	update_angle(float *angle, float value)
{
	(*angle) += value;
	if ((*angle) < 0)
		(*angle) += 360;
	if ((*angle) >= 360)
		(*angle) -= 360;
}

	/* Controle les angles en fonction des touches pressees */

void	handle_angle_control(int keycode, t_fdf *fdf)
{
	int	angle_step;

	angle_step = 1;
	if (fdf->key.leftctrl || fdf->key.rightctrl)
		angle_step = 90;
	if (keycode == UP)
		update_angle(&fdf->map.angle[0], -angle_step);
	if (keycode == DOWN)
		update_angle(&fdf->map.angle[0], angle_step);
	if (keycode == LEFT)
		update_angle(&fdf->map.angle[1], angle_step);
	if (keycode == RIGHT)
		update_angle(&fdf->map.angle[1], -angle_step);
	if (keycode == K_Q)
		update_angle(&fdf->map.angle[2], angle_step);
	if (keycode == K_W)
		update_angle(&fdf->map.angle[2], -angle_step);
}

	/* Controle le schema de couleurs en fonction des touches pressees */

void	control_colorscheme(int keycode, t_map *map)
{
	(void)keycode;
	map->colors.botco = BOTTOM_COLOR;
	map->colors.backco = DARK;
	map->colors.groundco = GROUND_COLOR;
	map->colors.topco = TOP_COLOR;
	apply_color(map);
}

	/* Comptes les sous-chaines dans une chaine */

int	count_substr(const char *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delimiter && in_word == 0 && *str != '\n')
		{
			in_word = 1;
			count++;
		}
		else if (*str == delimiter)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}
