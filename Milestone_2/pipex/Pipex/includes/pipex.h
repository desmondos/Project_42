/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:51:34 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:30:18 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

void	ft_show_usage(int is_exit);
int		ft_access_file(char *filename, int is_writable);
void	ft_free(char **tab);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_gent_env(char *filename, char **env);
char	*ft_get_path(char *cmd, char **env);
void	exec_cmd(char *cmd, char **env);
void	child_process(char **argv, int *parent_fd, char **env);
void	parent_process(char **argv, int *parent_fd, char **env);
int		main(int argc, char **argv, char **env);

#endif
