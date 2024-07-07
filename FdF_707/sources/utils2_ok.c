/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:05:42 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 14:07:09 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	to_round(double value)
{
	if (value < 0)
		return (int)(value - 0.5);
	return (int)(value + 0.5);
}

void	bi_free(char **str)
{
	int	pos;

	if (!str)
		return ;
	pos = 0;
	while (str[pos])
	{
		free(str[pos]);
		pos++;
	}
	free(str);
}

void	init_mat(float mat[3][3])
{
	int	row;
	int	col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			mat[row][col] = 0.0f;
			col++;
		}
		row++;
	}
}

void	mapcpy(t_dot *from, t_dot *to, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		to[pos] = from[pos];
		pos++;
	}
}

int	is_valid_pix(t_dot pix)
{
	if (pix.ax[0] < 0 || pix.ax[0] > WIN_WIDTH)
		return (0);
	if (pix.ax[1] < 0 || pix.ax[1] > WIN_HEIGHT)
		return (0);
	return (1);
}

