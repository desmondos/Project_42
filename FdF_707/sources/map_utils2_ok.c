/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2_ok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:00:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 15:20:27 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	import_color(int max, int min, t_dot *dot, t_color colors)
{
	dot->is_paint = 1;
	dot->color = DEFAULT;
	if (dot->hexa_color > 0)
	{
		dot->color = dot->hexa_color;
		return ;
	}
	if (dot->ax[2] == max)
		dot->color = colors.topCo;
	else if (dot->ax[2] == 0)
		dot->color = colors.groundCo;
	else if (dot->ax[2] == min && min != 0)
		dot->color = colors.botCo;
	else if (dot->ax[2] > 0)
		dot->color = inter_color(colors.groundCo,
						   colors.topCo, max, dot->ax[2]);
	else
		dot->color = inter_color(colors.botCo, colors.groundCo,
						   -min, -(min - dot->ax[2]));
}

int	is_hexaCo(char *line)
{
	int		get_color;
	char	**color;

	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(line, ',');
		get_color = ft_htoi(color[1]);
		bi_free(color);
		return (get_color);
	}
	else
		return (0);
}

int	ft_isxdigit(int c)
{
	return ((c >= '0' && c <= '9')
	|| (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int	ft_htoi(const char *str)
{
	int		value;
	char	digit;

	value = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str && ft_isxdigit(*str))
	{
		digit = *str++;
		if (digit >= '0' && digit <= '9')
			value = value * 16 + (digit - '0');
		else if (digit >= 'a' && digit <= 'f')
			value = value * 16 + (digit - 'a' + 10);
		else if (digit >= 'A' && digit <= 'F')
			value = value * 16 + (digit - 'A' + 10);
		else
			break;
	}
	return (value);
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
	return (1);
}

void	initColor(t_map *map)
{
	map->colors.backCo = BLACK;
	map->colors.botCo = BOTTOM_COLOR;
	map->colors.topCo = TOP_COLOR;
	map->colors.groundCo = GROUND_COLOR;
}

void	_init_map(t_map *map, int sum)
{
	if (sum)
	{
		map->length = 0;
		map->lim.ax[0] = 0;
		map->lim.ax[1] = 0;
		map->lim.ax[2] = 0;
		map->min_z = 0;
	}
	map->is_lines = 1;
	map->is_geom = 0;
	map->brange = 0;
	map->divide_z = 1;
	map->is_dots = 0;
	map->is_suplines = 0;
	map->is_shad = 1;
	map->from.ax[0] = WIN_WIDTH / 2;
	map->from.ax[1] = WIN_HEIGHT / 2;
	map->from.ax[2] = 0;
	map->angle[0] = 0;
	map->angle[1] = 0;
	map->angle[2] = 0;
	initColor(map);
}
