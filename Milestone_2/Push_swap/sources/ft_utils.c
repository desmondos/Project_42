/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:40:44 by candriam          #+#    #+#             */
/*   Updated: 2024/07/29 16:34:15 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atolong(const char *nptr)
{
	int		pos;
	int		is_neg;
	long	data;

	pos = 0;
	is_neg = 1;
	data = 0;
	while (nptr[pos] == 32 || (nptr[pos] >= 9 && nptr[pos] <= 13))
		pos++;
	if (nptr[pos] == '-')
	{
		is_neg *= -1;
		pos++;
	}
	else if (nptr[pos] == '+')
		pos++;
	while (nptr[pos])
	{
		if (!(nptr[pos] >= 48 && nptr[pos] <= 57))
			ft_puterror();
		data = data * 10 + (nptr[pos] - 48);
		pos++;
	}
	return (is_neg * data);
}

void	ft_rot_a(t_list **a, t_list *top)
{
	while (*a != top)
	{
		if (top->pre_mid)
			ft_ra(a);
		else
			ft_rra(a);
	}
}

void	ft_rot_b(t_list **b, t_list *top)
{
	while (*b != top)
	{
		if (top->pre_mid)
			ft_rb(b);
		else
			ft_rrb(b);
	}
}

t_list	*return_cheap(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list)
	{
		if (list->is_cheapest)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	ft_moves(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = return_cheap(*b);
	if (cheap == NULL || cheap->target == NULL)
		return ;
	if (cheap->pre_mid && cheap->target->pre_mid)
	{
		while (*b != cheap && *a != cheap->target)
			ft_rr(a, b);
	}
	else if (!(cheap->pre_mid) && !(cheap->target->pre_mid))
	{
		while (*b != cheap && *a != cheap->target)
			ft_rrr(a, b);
	}
	ft_rot_b(b, cheap);
	ft_rot_a(a, cheap->target);
	ft_pa(a, b);
}
