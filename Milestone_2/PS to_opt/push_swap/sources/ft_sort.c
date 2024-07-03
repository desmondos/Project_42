/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:59:48 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:23:33 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_is_sorted(t_list *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		else
			a = a->next;
	}
	return (true);
}

void	ft_easy_sort(t_list **a)
{
	t_list	*higher;

	higher = ft_is_higher(*a);
	if (*a == higher)
	{
		ft_ra(a);
		if ((*a)->data > (*a)->next->data)
			ft_sa(a);
	}
	else if ((*a)->next == higher)
	{
		ft_rra(a);
		if (ft_is_sorted(*a))
			return ;
		ft_sa(a);
	}
	else if ((*a)->data > (*a)->next->data)
		ft_sa(a);
}

void	ft_mid_sort(t_list **a, t_list **b)
{
	while (ft_stack_length(*a) > 3)
	{
		ft_init_nodes(*a, *b);
		ft_rot_a(a, find_min(*a));
		ft_pb(b, a);
	}
}
