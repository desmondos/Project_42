/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:20:30 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 15:09:49 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	borders(t_set *set)
{
	set->pos = 0;
	set->c_y = 1;
	while (set->c_y != set->map_height)
	{
		set->c_x = 1;
		while (set->c_x < set->map_width)
			borderless(set);
		if (set->c_x == set->map_width)
		{
			base_level(set);
			set->pos++;
		}
		set->c_y++;
	}
	set->c_x = 1;
	if (set->c_y == set->map_height)
	{
		while (set->c_x != set->map_width)
		{
			limits(set);
			set->pos++;
		}
	}
	free(set->finp);
}

void	limits(t_set *set)
{
	float	x_start;
	float	x_end;
	float	y_start;
	float	y_end;

	x_start = set->finp[set->pos].x;
	y_start = set->finp[set->pos].y;
	x_end = set->finp[set->pos + 1].x;
	y_end = set->finp[set->pos + 1].y;
	set->c_x++;
	draw_line(set, (t_finp){x_start, y_start}, (t_finp){x_end, y_end});
}

void	borderless(t_set *set)
{
	limits(set);
	base_level(set);
	set->pos++;
}

void	base_level(t_set *set)
{
	float	x_start;
	float	x_end;
	float	y_start;
	float	y_end;

	x_start = set->finp[set->pos].x;
	y_start = set->finp[set->pos].y;
	x_end = set->finp[set->pos + set->map_width].x;
	y_end = set->finp[set->pos + set->map_width].y;
	draw_line(set, (t_finp){x_start, y_start}, (t_finp){x_end, y_end});
}
