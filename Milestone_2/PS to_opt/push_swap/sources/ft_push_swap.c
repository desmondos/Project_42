/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:29:03 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:22:59 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_swap(t_list **a, t_list **b)
{
	t_list	*lowest;
	int		len_a;

	len_a = ft_stack_length(*a);
	if (len_a == 5)
		ft_mid_sort(a, b);
	else
		while (len_a-- > 3)
			ft_pb(b, a);
	ft_easy_sort(a);
	while (*b)
	{
		ft_init_nodes(*a, *b);
		ft_moves(a, b);
	}
	ft_setup_pos(*a);
	lowest = find_min(*a);
	if (lowest->pre_mid)
		while (*a != lowest)
			ft_ra(a);
	else
		while (*a != lowest)
			ft_rra(a);
}

void	ft_setup_pos(t_list *stack)
{
	int	pos;
	int	middle_stack;

	if (!stack)
		return ;
	pos = 0;
	middle_stack = ft_stack_length(stack) / 2;
	while (stack)
	{
		stack->cur_pos = pos;
		if (pos <= middle_stack)
			stack->pre_mid = true;
		else
			stack->pre_mid = false;
		stack = stack->next;
		pos++;
	}
}

void	ft_setup_target(t_list *a, t_list *b)
{
	t_list	*cur_a;
	t_list	*target;
	long	match_data;

	while (b)
	{
		match_data = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->data > b->data && cur_a->data < match_data)
			{
				match_data = cur_a->data;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (LONG_MAX == match_data)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	ft_set_cheapest(t_list *b)
{
	t_list	*cheapest_node;
	long	cheapest_data;

	if (!b)
		return ;
	cheapest_data = LONG_MAX;
	while (b)
	{
		if (b->cost < cheapest_data)
		{
			cheapest_data = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->is_cheapest = true;
}

void	ft_set_cost(t_list *a, t_list *b)
{
	int		length_a;
	int		length_b;

	length_a = ft_stack_length(a);
	length_b = ft_stack_length(b);
	while (b)
	{
		b->cost = b->cur_pos;
		if (!(b->pre_mid))
			b->cost = length_b - (b->cur_pos);
		if (b->target->pre_mid)
			b->cost += b->target->cur_pos;
		else
			b->cost += length_a - (b->target->cur_pos);
		b = b->next;
	}
}
