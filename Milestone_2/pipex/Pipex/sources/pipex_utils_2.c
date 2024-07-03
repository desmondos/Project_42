/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:55:04 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:44 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_access_file(char *filename, int is_writable)
{
	int	get;

	if (is_writable == 0)
		get = open(filename, O_RDONLY, 0777);
	if (is_writable == 1)
		get = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (is_writable == -1)
		exit(0);
	return (get);
}

void	exec_cmd(char *cmd, char **env)
{
	char	*path;
	char	**scmd;

	scmd = ft_split(cmd, ' ');
	if (!scmd)
		exit(1);
	path = ft_get_path(scmd[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: commamd not found ", 2);
		ft_putendl_fd(scmd[0], 2);
		ft_free(scmd);
		exit(0);
	}
	if (execve(path, scmd, env) == -1)
	{
		ft_free(scmd);
		exit(1);
	}
}

void	child_process(char **argv, int *parent_fd, char **env)
{
	int	fd;

	fd = ft_access_file(argv[1], 0);
	dup2(fd, 0);
	dup2(parent_fd[1], 1);
	close(parent_fd[0]);
	exec_cmd(argv[2], env);
}

void	parent_process(char **argv, int *parent_fd, char **env)
{
	int	fd;

	fd = ft_access_file(argv[4], 1);
	dup2(fd, 1);
	dup2(parent_fd[0], 0);
	close(parent_fd[1]);
	exec_cmd(argv[3], env);
}
