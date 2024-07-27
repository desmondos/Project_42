/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:25:56 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:26:19 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (check_init(&fdf, argc, argv[1]) != 0)
		return (1);
	main_init(&fdf);
	if (import_mcheck(&fdf, argv[1]) != 0)
	{
		clean_up(&fdf);
		return (1);
	}
	drawing_check(&fdf);
	all_hooks(&fdf);
	mlx_loop(fdf.set.mlx);
	to_clean(&fdf);
	clean_up(&fdf);
	return (0);
}

int	count_dots(t_fdf *fdf, const char *filename)
{
	int	fd;

	fdf->map.height = 0;
	fdf->is_first_line = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (puterror("wrong or file doesn't exist."), 1);
	fdf->line = get_next_line(fd);
	while (fdf->line)
	{
		fdf->length = 0;
		fdf->length = count_sub(fdf->line, 32);
		if (fdf->is_first_line)
		{
			fdf->first_line_len = fdf->length;
			fdf->map.length = fdf->first_line_len;
			fdf->is_first_line = 0;
		}
		if (fdf->length != fdf->first_line_len)
			return (free(fdf->line), close(fd), 1);
		fdf->map.height++;
		free(fdf->line);
		fdf->line = get_next_line(fd);
	}
	return (close(fd), (fdf->map.length * fdf->map.height));
}

int	count_sub(const char *str, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delimiter && in_word == 0 && *str != '\n')
		{
			in_word = 1;
			count++;
		}
		else if (*str == delimiter)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
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
	map->scale = 0.01;
	map->is_geom = 0;
	map->brange = 0;
	map->divide_z = 1;
	map->is_dots = 0;
	map->is_suplines = 0;
	map->is_shad = 1;
	map->from.ax[0] = WIN_WIDTH / 2;
	map->from.ax[1] = WIN_HEIGHT / 2;
	map->from.ax[2] = 0;
	map->angle[0] = 52;
	map->angle[1] = 45;
	map->angle[2] = 331;
	initcolor(map);
}

void	for_map_get_dots(t_fdf *fdf)
{
	free(fdf->map.dots);
	puterror("error memalloc");
}
