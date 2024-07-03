/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 06:49:06 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 16:22:32 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_puterror(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_is_dup(t_list *a, int input)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->data == input)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_input_error(char *input)
{
	int	pos;

	pos = 0;
	if (!(input[pos] >= 48 && input[pos] <= 57)
		|| input[pos] == '-' || input[pos] == '+')
		return (1);
	if ((input[pos] == '-' || input[pos] == '+')
		&& !(input[pos + 1] >= 48 && input[pos + 1] <= 57))
		return (1);
	while (input[pos++])
	{
		if (!(input[pos] >= 48 && input[pos] <= 57))
			return (1);
	}
	return (0);
}
