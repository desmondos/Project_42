/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:52:40 by candriam          #+#    #+#             */
/*   Updated: 2024/08/02 22:39:36 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
	/* readline: Obtenir une ligne d'un utilisateur en cours d'execution */
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

int	main(int argc, char **argv);

#endif
