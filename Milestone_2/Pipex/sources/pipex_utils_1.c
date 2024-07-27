/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:56:05 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:35 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_show_usage(int is_exit)
{
	if (is_exit == 1)
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(0);
}

void	ft_free(char **tab)
{
	int	pos;

	pos = 0;
	while (tab[pos])
	{
		free(tab[pos]);
		pos++;
	}
	free(tab);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

char	*ft_gent_env(char *filename, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, filename) == 0)
		{
			free(sub);
			return (env[i] + j +1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		pos;
	char	*exec;
	char	*part_path;
	char	**full_path;
	char	**s_cmd;

	pos = -1;
	full_path = ft_split(ft_gent_env("PATH", env), ':');
	s_cmd = ft_split(cmd, 32);
	while (full_path[++pos])
	{
		part_path = ft_strjoin(full_path[pos], "/");
		exec = ft_strjoin(part_path, s_cmd[0]);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free(full_path);
	ft_free(s_cmd);
	return (cmd);
}
