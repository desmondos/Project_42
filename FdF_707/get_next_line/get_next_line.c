/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:28:26 by candriam          #+#    #+#             */
/*   Updated: 2024/03/26 10:51:23 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(t_data *list)
{
	int		length;
	char	*newstr;

	if (!list)
		return (NULL);
	length = ft_newline_len(list);
	newstr = malloc(length + 1);
	if (!newstr)
		return (NULL);
	ft_subcpy(list, newstr);
	return (newstr);
}

void	ft_addback(t_data **list, char *sub)
{
	t_data	*lastlst;
	t_data	*newlst;

	lastlst = ft_is_lastlst(*list);
	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return ;
	if (!lastlst)
		*list = newlst;
	else
		lastlst->next = newlst;
	newlst->data = sub;
	newlst->next = NULL;
}

void	ft_makelst(t_data **list, int fd)
{
	int		nchar;
	char	*sub;

	while (!ft_is_newline(*list))
	{
		sub = malloc(BUFFER_SIZE + 1);
		if (!sub)
			return ;
		nchar = read(fd, sub, BUFFER_SIZE);
		if (!nchar)
		{
			free(sub);
			return ;
		}
		sub[nchar] = '\0';
		ft_addback(list, sub);
	}
}

void	ft_cleanlst(t_data **list)
{
	t_data	*lastlst;
	t_data	*new;
	char	*sub;
	int		pos_data;
	int		pos_sub;

	pos_sub = 0;
	pos_data = 0;
	sub = malloc(BUFFER_SIZE + 1);
	new = malloc(sizeof(t_list));
	lastlst = ft_is_lastlst(*list);
	if (!sub || !new)
		return ;
	while (!NULL && lastlst->data[pos_data] != '\n')
		pos_data++;
	while (!NULL && lastlst->data[pos_data++])
		sub[pos_sub++] = lastlst->data[pos_data];
	sub[pos_sub] = '\0';
	new->data = sub;
	new->next = NULL;
	ft_clean_alloc(list, new, sub);
}

char	*get_next_line(int fd)
{
	static t_data	*list;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, &new_line, 0) < 0)
		return (NULL);
	ft_makelst(&list, fd);
	if (!list)
		return (NULL);
	new_line = ft_getline(list);
	ft_cleanlst(&list);
	return (new_line);
}

#include <stdio.h>

int	main(void)
{
	int		nb_lines;
	int		fd;
	char	*str;

	nb_lines = 1;
	fd = open("lorem.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
		printf("%d- %s\n", nb_lines++, str);
	return (0);
}
