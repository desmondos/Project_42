/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:05:42 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 14:50:42 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_zoom(int mousecode, int x, int y, t_set *set)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
	{
		while (set->scale > -MAX_ZOOM)
		{
			set->scale *= ZOOM_FACTOR;
			break ;
		}
	}
	else if (mousecode == 5 && set->scale < -MIN_ZOOM)
		set->scale /= ZOOM_FACTOR;
	return (0);
}

int	mouse_release(int buton, int x, int y, t_set *set)
{
	(void)x;
	(void)y;
	if (buton == 1)
		set->is_dragging = 0;
	return (0);
}

int	mouse_press(int buton, int x, int y, t_set *set)
{
	(void)x;
	(void)y;
	if (buton == 1)
	{
		set->is_dragging = 1;
		set->last_x = x;
		set->last_y = y;
	}
	return (0);
}

int	mouse_move(int x, int y, t_set *set)
{
	int	dx;
	int	dy;

	if (set->is_dragging)
	{
		dx = x - set->last_x;
		dy = y - set->last_y;
		set->offset_x += dx;
		set->offset_y += dy;
		set->last_x = x;
		set->last_y = y;
	}
	return (0);
}

int	map_rotate(int keycode, t_set *set)
{
	if (keycode == 65505)
		set->is_shift = 1;
	else if (keycode == 65507)
		set->is_ctrl = 1;
	else if (keycode == 120 && set->is_shift)
		set->angle_x -= ROT;
	else if (keycode == 120 && set->is_ctrl)
		set->angle_x += ROT;
	else if (keycode == 121 && set->is_shift)
		set->angle_y -= ROT;
	else if (keycode == 121 && set->is_ctrl)
		set->angle_y += ROT;
	else if (keycode == 122 && set->is_shift)
		set->angle_z -= ROT;
	else if (keycode == 122 && set->is_ctrl)
		set->angle_z += ROT;
	else if (keycode == 114 && set->is_ctrl)
		set->angle += ROT;
	else if (keycode == 114 && set->is_shift)
		set->angle -= ROT;
	return (0);
}
