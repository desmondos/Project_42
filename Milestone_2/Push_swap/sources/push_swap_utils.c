/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:40:54 by candriam          #+#    #+#             */
/*   Updated: 2024/07/29 15:02:55 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_length(t_list *a)
{
	int	len;

	if (!a)
		return (0);
	len = 1;
	while (a->next)
	{
		len++;
		a = a->next;
	}
	return (len);
}

t_list	*ft_is_higher(t_list *a)
{
	long	higher;
	t_list	*highest;

	if (a == NULL)
		return (NULL);
	higher = INT_MIN;
	while (a)
	{
		if (a->data > higher)
		{
			higher = a->data;
			highest = a;
		}
		else
			a = a->next;
	}
	return (highest);
}

t_list	*find_min(t_list *a)
{
	long	lower;
	t_list	*lowest;

	if (a == NULL)
		return (NULL);
	lower = INT_MAX;
	while (a)
	{
		if (a->data < lower)
		{
			lower = a->data;
			lowest = a;
		}
		else
			a = a->next;
	}
	return (lowest);
}

int	ft_is_lowest(t_list *a)
{
	int	pos;

	pos = a->data;
	while (a)
	{
		if (a->data < pos)
			pos = a->data;
		else
			a = a->next;
	}
	return (pos);
}

t_list	*ft_lastlst(t_list *list)
{
	if (!list)
		return (NULL);
	while (list && list->next)
		list = list->next;
	return (list);
}
