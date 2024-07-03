/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/06/21 15:51:19 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	x_y_z_dim(t_set *set)
{
	int	pos;

	pos = 0;
	set->initp = malloc(set->map_height * set->map_width * (sizeof(t_initp)));
	if (!set->initp)
		puterror("allocation error");
	set->y = 0;
	while (set->y < set->map_height)
	{
		set->x = 0;
		while (set->x < set->map_width)
		{
			set->initp[pos] = (t_initp){set->x, set->y,
				set->tab[set->y][set->x]};
			pos++;
			set->x++;
		}
		set->y++;
	}
	free_tab(set);
}

void	x_y_dimension(t_set *set)
{
	int	pos;

	pos = 0;
	set->finp = malloc(set->map_height * set->map_width * (sizeof(t_finp)));
	if (!set->finp)
		puterror("allocation error");
	while (pos < (set->map_width * set->map_height))
	{
		set->finp[pos].y = set->initp[pos].y * cos(set->angle)
			+ set->initp[pos].y * cos(set->angle + 2) + (set->initp[pos].z
				* set->altitude) * cos(set->angle - 2);
		set->finp[pos].x = set->initp[pos].x * sin(set->angle)
			+ set->initp[pos].y * sin(set->angle + 2) + (set->initp[pos].z
				* set->altitude) * sin(set->angle - 2);
		set->finp[pos].x *= -set->scale;
		set->finp[pos].y *= set->scale;
		pos++;
	}
}
