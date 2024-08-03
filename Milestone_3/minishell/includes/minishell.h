/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:52:40 by candriam          #+#    #+#             */
/*   Updated: 2024/08/03 07:02:40 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
	/* readline: get a line from a user with editing */
# include <readline/readline.h>
# include <readline/history.h>
	/* our own library */
# include "libft.h"
# include "command.h"
# include "in_out.h"
# include "process.h"
# include "shell.h"
# include "signal.h"
# include "utils.h"

int	main(int argc, char **argv);

#endif
