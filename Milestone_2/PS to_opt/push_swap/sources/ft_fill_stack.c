/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:32:41 by candriam          #+#    #+#             */
/*   Updated: 2024/06/29 15:08:22 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(t_list **a, char *argv[])
{
	long	input;
	int		pos;

	pos = 0;
	while (argv[pos])
	{
		if (!(ft_input_error(argv[pos])))
			ft_puterror();
		input = ft_atolong(argv[pos]);
		if (input > INT_MAX || input < INT_MIN)
			ft_puterror();
		if (ft_is_dup(*a, (int)input))
			ft_puterror();
		ft_addback(a, (int)input);
		pos++;
	}
}

void	print_stack(t_list **pile)
{
	while (*pile)
	{
		printf("%d\n", (*pile)->data);
		*pile = (*pile)->next;
	}
}

void	ft_addback(t_list **stack, int input)
{
	t_list	*list;
	t_list	*lastlist;

	list = NULL;
	lastlist = NULL;
	if (!stack)
		return ;
	list = malloc(sizeof(t_list));
	if (!(list))
		return ;
	list->next = NULL;
	list->data = input;
	if (!(*stack))
	{
		*stack = list;
		list->prev = NULL;
	}
	else
	{
		lastlist = ft_lastlst(*stack);
		lastlist->next = list;
		list->prev = lastlist;
	}
}

void	ft_init_nodes(t_list *a, t_list *b)
{
	ft_setup_pos(a);
	ft_setup_pos(b);
	ft_setup_target(a, b);
	ft_set_cost(a, b);
	ft_set_cheapest(b);
}

void	main_sort(t_list *a)
{
	t_list	*b;

	b = NULL;
	if (!ft_is_sorted(a))
	{
		if (ft_stack_length(a) == 2)
			ft_sa(&a);
		else if (ft_stack_length(a) == 3)
			ft_easy_sort(&a);
		else
			ft_push_swap(&a, &b);
	}
}
