/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:56:00 by candriam          #+#    #+#             */
/*   Updated: 2024/07/27 17:14:19 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	char	*after_split;

	a = NULL;
	after_split = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], 32);
	else if (argc > 2)
	{
		after_split = arg_merge(argc, argv);
		if (!after_split)
			return (1);
		argv = ft_split(after_split, 32);
		free(after_split);
	}
	ft_init(&a, argv + 1);
	main_sort(a);
	arg_free(argv);
	return (0);
}
