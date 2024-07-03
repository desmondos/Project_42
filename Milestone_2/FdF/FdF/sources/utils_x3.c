/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:41 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 14:49:49 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	move_all_dir(int keycode, t_set *set)
{
	if (keycode == 65507)
		set->is_ctrl = 1;
	else if (keycode == 119)
		set->y_translation -= TRANS_FACTOR_Y;
	else if (keycode == 115)
		set->y_translation += TRANS_FACTOR_Y;
	else if (keycode == 97)
		set->x_translation -= TRANS_FACTOR_X;
	else if (keycode == 100)
		set->x_translation += TRANS_FACTOR_X;
	else if (keycode == 65364 && set->is_ctrl)
		set->y_translation -= TRANS_FACTOR_Y;
	else if (keycode == 65362 && set->is_ctrl)
		set->y_translation += TRANS_FACTOR_Y;
	else if (keycode == 65363 && set->is_ctrl)
		set->x_translation -= TRANS_FACTOR_X;
	else if (keycode == 65361 && set->is_ctrl)
		set->x_translation += TRANS_FACTOR_X;
	return (0);
}

int	altitude(int keycode, t_set *set)
{
	if (keycode == 65451)
		set->altitude += ALTITUDE;
	else if (keycode == 65453)
		set->altitude -= ALTITUDE;
	return (0);
}

int	set_map_color_dyn(int keycode, t_set *set)
{
	if (keycode == 103)
		set->color = GREEN;
	else if (keycode == 110)
		set->color = BLACK;
	else if (keycode == 102)
		set->color = WHITE;
	else if (keycode == 109)
		set->color = RED;
	else if (keycode == 98)
		set->color = BLUE;
	else if (keycode == 106)
		set->color = YELLOW;
	return (0);
}

int	set_bg_color_dyn(int keycode, t_set *set)
{
	if (keycode == 65433)
		set->bg = GREEN;
	else if (keycode == 65438)
		set->bg = BLACK;
	else if (keycode == 65436)
		set->bg = WHITE;
	else if (keycode == 65435)
		set->bg = RED;
	else if (keycode == 65430)
		set->bg = BLUE;
	else if (keycode == 65437)
		set->bg = YELLOW;
	return (0);
}

int	set_map_brightness(int keycode, t_set *set)
{
	if (keycode == 65506)
	{
		while (set->brightness < MAX_BRIGHT)
		{
			set->brightness += BRIGHT;
			break ;
		}
	}
	else if (keycode == 65508 && set->brightness > MIN_BRIGHT)
		set->brightness -= BRIGHT;
	return (0);
}
