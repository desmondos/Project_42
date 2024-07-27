/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:17:11 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	do_color(t_map *map)
{
	int	pos;

	if (map->dots == NULL)
		puterror("error: map->dots is NULL");
	pos = 0;
	while (pos < map->length)
	{
		import_color((int)map->lim.ax[2], map->min_z,
			&map->dots[pos], map->colors);
		pos++;
	}
}

void	import_color(int max, int min, t_dot *dot, t_color colors)
{
	if (dot == NULL)
		puterror("Error: dot is NULL");
	dot->is_paint = 1;
	dot->color = colors.botco;
	if (dot->hexa_color > 0)
	{
		dot->color = dot->hexa_color;
		return ;
	}
	if (dot->ax[2] == max)
		dot->color = colors.topco;
	else if (dot->ax[2] == 0)
		dot->color = colors.groundco;
	else if (dot->ax[2] == min && min != 0)
		dot->color = colors.botco;
	else if (dot->ax[2] > 0)
		dot->color = inter_color(colors.groundco,
				colors.topco, max, dot->ax[2]);
	else
		dot->color = inter_color(colors.botco, colors.groundco,
				-min, -(min - dot->ax[2]));
}

int	is_hexaco(char *line)
{
	int		get_color;
	char	**color;

	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(line, ',');
		if (!color)
			return (0);
		if (color[1] != NULL)
			get_color = ft_htoi(color[1]);
		else
			get_color = 0;
		bi_free((void **)color);
		return (get_color);
	}
	return (0);
}

int	is_valid_dot(char *value)
{
	int	valid;

	valid = 0;
	if (*value == '-' || *value == '+' || ft_isdigit(*value))
		valid++;
	value++;
	while (ft_isdigit(*value))
	{
		value++;
		valid++;
	}
	if (valid == 0)
		return (0);
	else
		return (1);
}

void	initcolor(t_map *map)
{
	map->colors.backco = BLACK;
	map->colors.botco = BOTTOM_COLOR;
	map->colors.topco = TOP_COLOR;
	map->colors.groundco = GROUND_COLOR;
}
