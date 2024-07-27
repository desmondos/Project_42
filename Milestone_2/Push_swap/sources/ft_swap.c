/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:56:15 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:24:07 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_list **stack)
{
	int	len;

	len = ft_stack_length(*stack);
	if (stack == NULL || (*stack)->next == NULL || len == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	ft_sa(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b)
{
	if (!(*a) || (*a)->next == NULL || !(*b) || (*b)->next == NULL)
		return ;
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
