/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 05:21:36 by candriam          #+#    #+#             */
/*   Updated: 2024/07/28 10:33:13 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

	/*
	* Un pipe est une maniere pour les processus de communiquer entre eux.
	* Un pipe permet la communication unidirectionnelle entre deux processus
	* Un pipe est essentiellement une paire de descripteurs de fichiers :
	*		- l'un est utilise pour lire a partir du pipe
	*		- et l'autre est utilise pour ecrire dans le pipe
	*
	*	On verifie le nombre des arguments si egal a 4 + le nom du programme,
	*	On cree un pipe pour permettre la communication entre le processus 
	* parent et l'enfant
	*	On cree le processus enfant en utilisant fork
	*	On sort avec un code d'erreur si la creation du processus echoue
	*	Si pid == 0, on est dans le processus enfant et on appelle la fonction
	* child_process, qui utilise parent_fd[1] pour ecrire dans le pipe,
	*	Sinon, on est dans le processus parent et on appelle la fonction
	* parent_process, aui utilise parent_fd[0] pour lire a partir du pipe.
	* */

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		show_usage_exit(1);
	if (pipe(pipe_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child_process(argv, pipe_fd, env);
	parent_process(argv, pipe_fd, env);
	return (0);
}
