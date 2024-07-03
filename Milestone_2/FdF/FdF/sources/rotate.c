/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:31:56 by candriam          #+#    #+#             */
/*   Updated: 2024/06/23 15:47:13 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_on_x(t_3D *point, float angle)
{
	float	y;
	float	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) - z * sin(angle);
	point->z = y * sin(angle) + z * cos(angle);
}

void	rotate_on_y(t_3D *point, float angle)
{
	float	x;
	float	z;

	x = point->x;
	z = point->z;
	point->x = x * cos(angle) + z * sin(angle);
	point->z = -x * sin(angle) + z * cos(angle);
}

void	rotate_on_z(t_3D *point, float angle)
{
	float	x;
	float	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
}
