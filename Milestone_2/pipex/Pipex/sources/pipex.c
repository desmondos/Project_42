/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 05:21:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:20 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		parent_fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_show_usage(1);
	if (pipe(parent_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child_process(argv, parent_fd, env);
	parent_process(argv, parent_fd, env);
	return (0);
}
