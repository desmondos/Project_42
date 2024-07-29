/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:32:41 by candriam          #+#    #+#             */
/*   Updated: 2024/07/29 16:34:56 by candriam         ###   ########.mg       */
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
		if (input > 2147483647 || input < -2147483648)
			ft_puterror();
		if (ft_is_dup(*a, (int)input))
			ft_puterror();
		ft_addback(a, (int)input);
		pos++;
	}
}

void	ft_addback(t_list **stack, int input)
{
	t_list	*list;
	t_list	*lastlist;

	if (!stack)
		return ;
	list = malloc(sizeof(t_list));
	if (!(list))
		return ;
	list->next = NULL;
	list->data = input;
	list->prev = NULL;
	list->target = NULL;
	list->is_cheapest = 0;
	list->pre_mid = 0;
	if (!(*stack))
		*stack = list;
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
	ft_set_move(a, b);
	ft_set_cheapest(b);
}

void	free_list(t_list **stack)
{
	t_list	*stash;
	t_list	*cur;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		stash = cur;
		cur = cur->next;
		free(stash);
	}
	*stack = NULL;
}
