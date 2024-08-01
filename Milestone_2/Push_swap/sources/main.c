/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:56:00 by candriam          #+#    #+#             */
/*   Updated: 2024/08/01 15:27:53 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	char	*merged_arg;

	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], 32);
	else if (argc > 2)
	{
		merged_arg = arg_merge(argc, argv);
		if (!merged_arg)
			return (1);
		argv = ft_split(merged_arg, 32);
		free(merged_arg);
	}
	if (initialize_stack(&a, argv + 1) == 1)
	{
		free_arg(argv);
		free_stack(&a);
		puterror_exit();
	}
	main_sort(a);
	free_arg(argv);
	return (0);
}
