/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:56:05 by candriam          #+#    #+#             */
/*   Updated: 2024/07/28 10:33:10 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

	/* Affiche l'utilisation correcte du programme dans 
	 * la sortie d'erreur standard et termine l'execution */

void	show_usage_exit(int should_exit)
{
	if (should_exit == 1)
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(0);
}

	/* Libere la memoire allouee pour un tableau de string 
	 * Libere chaque chaine de caractere dans le tableau
	 * puis libere le tableau lui-meme. */

void	free_str_array(char **array)
{
	int	pos;

	pos = 0;
	while (array[pos])
	{
		free(array[pos]);
		pos++;
	}
	free(array);
}

	/* Compare deux strings et retoure la difference entre les deux strings */

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

	/* Trouve la valeur d'une variable d'environnement
	 * puis extrait la substring jusqu'au signe '='
	 * ensuite retourne la valeur du variable de l'env */

char	*gent_env_value(char *key, char **env)
{
	int		i;
	int		key_len;
	char	*sub_key;

	i = 0;
	while (env[i])
	{
		key_len = 0;
		while (env[i][key_len] && env[i][key_len] != '=')
			key_len++;
		sub_key = ft_substr(env[i], 0, key_len);
		if (ft_strcmp(sub_key, key) == 0)
		{
			free(sub_key);
			return (env[i] + key_len +1);
		}
		free(sub_key);
		i++;
	}
	return (NULL);
}

	/* Trouve le chemin complet de l'executable pour une commande donnee
	 * ensuite, divise la variable PATH en chemins ainsi que la commmande
	 * en arguments puis construit un chemin complet vers l'executable
	 * puis, verifier si le fichier est accessible et executable,
	 * si oui, retourne directement le chemin complet de l'executable
	 * et enfin, retourne la commande elle-meme si aucun chemin valide
	 * n'est trouve. */

char	*get_executable_path(char *command, char **env)
{
	int		path_index;
	char	*full_path;
	char	*part_path;
	char	**path_dir;
	char	**command_part;

	path_index = -1;
	path_dir = ft_split(gent_env_value("PATH", env), ':');
	command_part = ft_split(command, 32);
	while (path_dir[++path_index])
	{
		part_path = ft_strjoin(path_dir[path_index], "/");
		full_path = ft_strjoin(part_path, command_part[0]);
		free(part_path);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_str_array(command_part);
			return (full_path);
		}
		free(full_path);
	}
	free_str_array(path_dir);
	free_str_array(command_part);
	return (command);
}
