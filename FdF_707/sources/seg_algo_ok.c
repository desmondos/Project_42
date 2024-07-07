/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_algo_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/07 16:25:43 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	parsing(t_fdf *fdf, t_dot *proj)
{
	divide_z(proj, fdf->map.divide_z, fdf->map.length);
	applynew_z(proj, fdf->map.length, fdf->map.brange);
	if (fdf->map.is_geom)
		to_sphere(&fdf->map, proj);
	rotate_on_x(proj, proj, fdf->map.angle[0], fdf->map.length);
	rotate_on_y(proj, proj, fdf->map.angle[1], fdf->map.length);
	rotate_on_z(proj, proj, fdf->map.angle[2], fdf->map.length);
	if (fdf->map.is_geom && fdf->map.is_shad)
		dot_to_paint(proj, fdf->map.length);
	orto_proj(proj, proj, fdf->map.length);
	scales(proj, fdf->map.scale, fdf->map.length);
	moves(proj, fdf->map.from, fdf->map.length);
}

int	lim_checks(t_dot *dots, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		if (dots[pos].ax[0] > WIN_WIDTH - MARGIN)
			return (1);
		if (dots[pos].ax[1] < MARGIN || dots[pos].ax[1]
			> (WIN_HEIGHT - MARGIN))
			return (1);
		pos++;
	}
	return (0);
}

void	corres_screen(t_fdf *fdf, t_dot *proj)
{
	fdf->map.from.ax[0] = (WIN_WIDTH / 2);
	fdf->map.from.ax[1] = WIN_HEIGHT / 2;
	fdf->map.from.ax[2] = 0;
	fdf->map.scale = 1;
	mapcpy(fdf->map.dots, proj, fdf->map.length);
	parsing(fdf, proj);
	while (!(lim_checks(proj, fdf->map.length)))
	{
		mapcpy(fdf->map.dots, proj, fdf->map.length);
		parsing(fdf, proj);
		fdf->map.scale += 0.2;
	}
}

void	drawing(t_fdf *fdf, t_dot *proj, int fit)
{
	if (fit)
		corres_screen(fdf, proj);
	if (fdf->map.is_lines)
		wired(fdf, proj);
	if (fdf->map.is_dots)
		is_doted(fdf, proj);
}

int	draw_fdf(t_fdf *fdf, int sized)
{
	t_dot	*proj;

	proj = malloc(fdf->map.length * sizeof(t_dot));
	if (proj == NULL)
		return (1);
	fdf->map.render += 1;
	set_background(fdf, fdf->map.colors.backCo);
	mapcpy(fdf->map.dots, proj, fdf->map.length);
	parsing(fdf, proj);
	drawing(fdf, proj, sized);
	mlx_put_image_to_window(fdf->set.mlx, fdf->set.win,
						 fdf->b_map.img, 0, 0);
	free(proj);
	return (1);
}

void	import_map(t_map *map, char *filepath)
{
	int	fd;

	_init_map(map, 1);
	fd = open(filepath, O_RDONLY);
	if (fd < 2)
		return ;
	map->mem = reading(fd);
	close (fd);
	map_size(map);
	map_get_dots(map);
	do_color(map);
	to_pol(map);
}

char	*reading(int fd)
{
	static int	byte_readed = READ;
	static int	all_bytes = 0;
	char		*buf;
	char		*stash;
	char		*map;

	buf = malloc(READ * sizeof(char));
	if (buf == NULL)
		return (NULL);
	map = ft_strdup("");
	while (byte_readed == READ)
	{
		ft_bzero(buf, READ);
		byte_readed = read(fd, buf, READ);
		stash = map;
		map = ft_strjoin(map, buf);
		all_bytes += byte_readed;
		free (stash);
	}
	free(buf);
	return (map);
}

int	import_dots(char *line, t_map *map, int line_nbr)
{
	char		**split;
	int			pos;
	static int	index = 0;

	split = ft_split(line, 32);
	pos = 0;
	while (split[pos] && split[pos][0] != '\n')
	{
		if (!is_valid_dot(&split[pos][0]))
			return (1);
		map->dots[index].ax[2] = ft_atoi(&split[pos][0]);
		map->dots[index].ax[0] = pos - map->lim.ax[0] / 2;
		map->dots[index].ax[1] = line_nbr - map->lim.ax[1] / 2;
		map->dots[index].is_paint = 1;
		map->dots[index].color = DEFAULT;
		map->dots[index].hexa_color = is_hexaCo(split[pos]);
		if (map->lim.ax[2] < map->dots[index].ax[2])
			map->lim.ax[2] = map->dots[index].ax[2];
		if (map->min_z > map->dots[index].ax[2])
			map->min_z = map->dots[index].ax[2];
		pos++;
		index++;
	}
	bi_free(split);
	return (pos);
}

void	map_size(t_map *map)
{
	static int	pos = -1;
	static int	elem = 0;

	while (map->mem[++pos])
	{
		if (map->mem[pos] == '\n' && map->mem[pos + 1] == '\0')
			break;
		if (ft_isalnum(map->mem[pos])&& (map->mem[pos + 1] == 32
			|| map->mem[pos + 1] == '\n' || map->mem[pos + 1] == '\0'))
			elem++;
		if (map->mem[pos] == '\n')
		{
			map->lim.ax[1]++;
			if (map->lim.ax[0] != 0 && (map->lim.ax[0] != elem))
				return;
			map->lim.ax[0] = elem;
			elem = 0;
		}
	}
	if (elem > 0 && (map->lim.ax[0] != elem))
		return ;
	map->lim.ax[1]++;
	map->length = map->lim.ax[0] * map->lim.ax[1];
}

void	map_get_dots(t_map *map)
{
	static int	num_dots = 0;
	static int	num_line = 0;
	int			pos;
	char		*line;
	char		*last;

	last = map->mem;
	line = NULL;
	pos = 0;
	map->dots = ft_calloc(map->length, sizeof(t_dot));
	while (++pos)
	{
		if (map->mem[pos] == '\n' || map->mem[pos] == '\0')
		{
			free(line);
			line = ft_substr(last, 0, &map->mem[pos] - last);
			last = &map->mem[pos + 1];
			num_dots += import_dots(line, map, num_line++);
			if (map->mem[pos] == '\0')
				break;
		}
	}
	free(line);
}
