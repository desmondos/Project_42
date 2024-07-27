/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 07:39:47 by candriam          #+#    #+#             */
/*   Updated: 2024/07/27 17:13:58 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_set_top(t_list **a)
{
	long	min;
	long	stash;

	min = ft_is_lowest(*a);
	if ((*a)->data > min)
	{
		stash = (*a)->data;
		(*a)->data = min;
		min = stash;
	}
}

void	ft_set_cur(t_list *a)
{
	int	pos;
	int	mid;

	pos = 0;
	if (a == NULL)
		return ;
	mid = ft_stack_length(a) / 2;
	while (a)
	{
		a->cur_pos = pos;
		if (pos <= mid)
			a->pre_mid = true;
		a->pre_mid = false;
		a = a->next;
		pos++;
	}
}
