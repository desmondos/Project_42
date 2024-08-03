/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:00:44 by candriam          #+#    #+#             */
/*   Updated: 2024/08/03 08:59:38 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char	*input;

	input = readline("$> ");
	if (input && *input)
	{
		printf("You entered: %s\n", input);

		//add_history(input);

		free(input);
	}
	else
		printf("Error or end of file\n");
	return (0);
}
