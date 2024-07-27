/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:14:11 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:23:12 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	int		len;

	len = ft_stack_length(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = ft_lastlst(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	ft_rra(t_list **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	rev_rot_all(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap->target && *b != cheap)
		ft_rrr(a, b);
	ft_setup_pos(*a);
	ft_setup_pos(*b);
}
