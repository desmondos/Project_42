/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:34:31 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 15:08:26 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_info(t_set *set, char *filename)
{
	int		fd;
	char	*line;
	char	**sub;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		puterror("map error");
	line = get_next_line(fd);
	if (!line)
		puterror("empty map");
	sub = ft_split(line, ' ');
	while (sub[set->map_width])
	{
		free(sub[set->map_width]);
		set->map_width++;
	}
	while (line)
	{
		free(line);
		set->map_height++;
		line = get_next_line(fd);
	}
	free(line);
	free(sub);
	close(fd);
}

void	check_map(t_set *set, char *filename)
{
	int		fd;
	int		pos;
	char	*line;
	char	**sub;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		sub = ft_split(line, ' ');
		free(line);
		pos = 0;
		while (sub[pos])
		{
			free(sub[pos]);
			pos++;
		}
		free(sub);
		if (pos < set->map_width || pos > set->map_width)
			puterror("wrong map width");
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	parsing(t_set *set, char *filename)
{
	int		fd;
	char	*line;
	char	**sub_line;

	fd = open(filename, O_RDONLY);
	set->tab = malloc(sizeof(int *) * set->map_height);
	if (!set->tab)
		puterror("allocation failed");
	while (set->y < set->map_height)
	{
		set->tab[set->y] = malloc(sizeof(int) * set->map_width);
		if (!set->tab[set->y])
			puterror("allocation failed");
		line = get_next_line(fd);
		sub_line = ft_split(line, ' ');
		free(line);
		set->x = -1;
		while (++set->x < set->map_width)
		{
			set->tab[set->y][set->x] = ft_atoi(sub_line[set->x]);
			free(sub_line[set->x]);
		}
		set->y++;
		free(sub_line);
	}
}

int	init_set(t_set *set, char *filename)
{
	char	*win_title;

	win_title = ft_strjoin(TITLE, filename);
	set->mlx = mlx_init();
	if (set->mlx == NULL)
	{
		free(set->mlx);
		return (1);
	}
	set->win = mlx_new_window(set->mlx, WIN_WIDTH, WIN_HEIGHT, win_title);
	if (set->win == NULL)
		return (1);
	set->img = mlx_new_image(set->mlx, WIN_WIDTH, WIN_HEIGHT);
	set->addr = mlx_get_data_addr(set->img, &set->bpp, &set->len, &set->endi);
	x_y_dimension(set);
	borders(set);
	all_hook(set);
	mlx_loop_hook(set->mlx, performer, set);
	mlx_loop(set->mlx);
	return (0);
}

int	performer(t_set *set)
{
	display_background(set);
	x_y_dimension(set);
	borders(set);
	mlx_put_image_to_window(set->mlx, set->win, set->img, 0, 0);
	return (0);
}
