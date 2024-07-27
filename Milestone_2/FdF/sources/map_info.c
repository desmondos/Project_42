/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:05:42 by candriam          #+#    #+#             */
/*   Updated: 2024/07/23 11:26:29 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*reading(int fd, t_fdf *fdf)
{
	static int	byte_readed = READ;
	static int	tot_bytes = READ;

	fdf->buf = malloc(READ + 1);
	if (!fdf->buf)
		return (terminate("failed to allocate buf in reading"), NULL);
	fdf->maps = ft_strdup("");
	if (!fdf->maps)
		return (free(fdf->buf), terminate("failed to alloc"), NULL);
	byte_readed = read(fd, fdf->buf, READ);
	while (byte_readed > 0)
	{
		fdf->buf[byte_readed] = '\0';
		fdf->stash = fdf->maps;
		fdf->maps = ft_strjoin(fdf->maps, fdf->buf);
		if (!fdf->maps)
			return (free(fdf->stash), free(fdf->buf), terminate("read"), NULL);
		free(fdf->stash);
		tot_bytes += byte_readed;
		byte_readed = read(fd, fdf->buf, READ);
	}
	if (byte_readed < 0)
		return (free(fdf->maps), free(fdf->buf), terminate("reading"), NULL);
	return (free(fdf->buf), fdf->maps);
}

void	map_size(t_map *map)
{
	static int	pos = 0;
	static int	elem = 0;

	while (map->mem[pos])
	{
		if (map->mem[pos] == '\n' && map->mem[pos + 1] == '\0')
			break ;
		if (ft_isalnum(map->mem[pos]) && (map->mem[pos + 1] == ' '
				|| map->mem[pos + 1] == '\n' || map->mem[pos + 1] == '\0'))
			elem++;
		if (map->mem[pos] == '\n')
		{
			map->lim.ax[1]++;
			if (map->lim.ax[0] != 0 && (map->lim.ax[0] != elem))
				return ;
			else
				map->lim.ax[0] = elem;
			elem = 0;
		}
		pos++;
	}
	if (elem > 0 && (map->lim.ax[0] != elem))
		return ;
	map->lim.ax[1]++;
	map->length = map->lim.ax[0] * map->lim.ax[1];
}

int	lim_checks(t_dot *dots, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		if (dots[pos].ax[0] > WIN_WIDTH - MARGIN)
			return (1);
		if (dots[pos].ax[1] < MARGIN
			|| dots[pos].ax[1] > (WIN_HEIGHT - MARGIN))
			return (1);
		pos++;
	}
	return (0);
}
