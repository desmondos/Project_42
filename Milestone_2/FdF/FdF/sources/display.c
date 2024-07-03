/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:26:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 14:10:14 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	main_input(t_set *set)
{
	set->brightness = 0.2;
	set->map_height = 0;
	set->map_width = 0;
	set->x_translation = 0;
	set->y_translation = 0;
	set->y = 0;
	set->altitude = 0.1;
	set->scale = -2;
	set->angle = -7.7;
	set->angle_x = 0.5;
	set->angle_y = 0;
	set->angle_z = 0.5;
	set->color = DEFAULT;
	set->bg = BLACK;
}

void	free_tab(t_set *set)
{
	int	y;

	y = 0;
	while (set->map_height > y)
	{
		free(set->tab[y]);
		y++;
	}
	free(set->tab);
}

float	vabs(float value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	calculate(t_calc *calc, t_finp start, t_finp end)
{
	calc->diff.dx = end.x - start.x;
	calc->diff.dy = end.y - start.y;
	if (vabs(calc->diff.dx) >= vabs(calc->diff.dy))
		calc->move = vabs(calc->diff.dx);
	else
		calc->move = vabs(calc->diff.dy);
	calc->diff.dx = calc->diff.dx / calc->move;
	calc->diff.dy = calc->diff.dy / calc->move;
	calc->x = start.x;
	calc->y = start.y;
}

void	all_rot(t_set *set, t_finp *start, t_finp *end)
{
	t_3D	point_end;
	t_3D	point_start;

	point_start.x = start->x;
	point_start.y = start->y;
	point_start.z = 0;
	point_end.x = end->x;
	point_end.y = end->y;
	point_end.z = 0;
	rotate_on_x(&point_start, set->angle_x);
	rotate_on_y(&point_start, set->angle_y);
	rotate_on_z(&point_start, set->angle_z);
	rotate_on_x(&point_end, set->angle_x);
	rotate_on_y(&point_end, set->angle_y);
	rotate_on_z(&point_end, set->angle_z);
	start->x = point_start.x;
	start->y = point_start.y;
	end->x = point_end.x;
	end->y = point_end.y;
}
