/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:18:02 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:25:58 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		puterror("alloc error");
	fdf->map.render++;
	set_background(fdf, fdf->map.colors.backco);
	if (fdf->map.dots != NULL)
	{
		mapcpy(fdf->map.dots, proj, fdf->map.length);
		parsing(fdf, proj);
		drawing(fdf, proj, sized);
		mlx_put_image_to_window(fdf->set.mlx, fdf->set.win,
			fdf->b_map.img, 0, 0);
	}
	else
	{
		free(proj);
		puterror("error mem");
	}
	free(proj);
	return (0);
}

int	import_map(t_fdf *fdf, char *filepath)
{
	int	fd;

	_init_map(&fdf->map, 1);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (puterror("open file failed"), 1);
	fdf->map.mem = reading(fd, fdf);
	if (fdf->map.mem == NULL)
		return (puterror("read file failed."), close(fd), 1);
	else
	{
		map_size(&fdf->map);
		map_get_dots(fdf);
		do_color(&fdf->map);
		to_pol(&fdf->map);
		if (fdf->map.dots == NULL)
			return (puterror("failed to generate dots"),
				free(fdf->map.mem), fdf->map.mem = NULL, close(fd), 1);
	}
	close(fd);
	return (0);
}

int	import_dots(char *line, t_fdf *fdf, int line_nbr)
{
	static int	index = 0;

	if (line_nbr == 0)
		index = 0;
	fdf->splits = ft_split(line, ' ');
	if (!fdf->splits)
		return (puterror("error at import dots"), 1);
	fdf->pos = 0;
	while (fdf->splits[fdf->pos] && fdf->splits[fdf->pos][0] != '\n')
	{
		check_imp_dots(fdf, index);
		fdf->map.dots[index].ax[2] = ft_atoi(fdf->splits[fdf->pos]);
		fdf->map.dots[index].ax[0] = fdf->pos - fdf->map.lim.ax[0] / 2;
		fdf->map.dots[index].ax[1] = line_nbr - fdf->map.lim.ax[1] / 2;
		fdf->map.dots[index].is_paint = 1;
		fdf->map.dots[index].color = DEFAULT;
		fdf->map.dots[index].hexa_color = is_hexaco(fdf->splits[fdf->pos]);
		if (fdf->map.lim.ax[2] < fdf->map.dots[index].ax[2])
			fdf->map.lim.ax[2] = fdf->map.dots[index].ax[2];
		if (fdf->map.min_z > fdf->map.dots[index].ax[2])
			fdf->map.min_z = fdf->map.dots[index].ax[2];
		fdf->pos++;
		index++;
	}
	return (free_split(fdf->splits), fdf->pos);
}

void	map_get_dots(t_fdf *fdf)
{
	static int	num_dots = 0;
	static int	num_line = 0;
	int			pos;

	fdf->last = fdf->map.mem;
	fdf->line = NULL;
	pos = 0;
	fdf->map.dots = ft_calloc(fdf->map.length, sizeof(t_dot));
	if (!fdf->map.dots)
		puterror("error at seg_algo map_get_dots");
	while (++pos)
	{
		if (fdf->map.mem[pos] == '\n' || fdf->map.mem[pos] == '\0')
		{
			free(fdf->line);
			fdf->line = ft_substr(fdf->last, 0, &fdf->map.mem[pos] - fdf->last);
			if (!fdf->line)
				for_map_get_dots(fdf);
			fdf->last = &fdf->map.mem[pos + 1];
			num_dots += import_dots(fdf->line, fdf, num_line++);
			if (fdf->map.mem[pos] == '\0')
				break ;
		}
	}
	free(fdf->line);
}
