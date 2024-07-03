/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:10 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 15:04:44 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ftoi(float value)
{
	return ((int)value);
}

float	fract_part(float value)
{
	if (value > 0.f)
		return (value - ftoi(value));
	return (value - (ftoi(value) + 1.f));
}

float	rest_fract_part(float value)
{
	return (1.f - fract_part(value));
}

void	ft_swap(int *x, int *y)
{
	int	stash;

	stash = *x;
	*x = *y;
	*y = stash;
}
