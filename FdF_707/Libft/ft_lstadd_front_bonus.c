/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:08:33 by candriam          #+#    #+#             */
/*   Updated: 2024/02/29 11:27:30 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list	**lst, t_list *news)
{
	if (lst == NULL && news == NULL)
		return ;
	else
	{
		news->next = *lst;
		*lst = news;
	}
}
