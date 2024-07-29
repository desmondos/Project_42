/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:56:00 by candriam          #+#    #+#             */
/*   Updated: 2024/07/29 15:02:14 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calc_len(int ac, char **av)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	return (len);
}

char	*arg_merge(int ac, char **av)
{
	char	*after_split;
	int		len;
	int		i;

	len = calc_len(ac, av);
	after_split = (char *)malloc(sizeof(char) * (len + 1));
	if (!after_split)
		return (NULL);
	after_split[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(after_split, av[i]);
		if (i < ac - 1)
			ft_strcat(after_split, " ");
		i++;
	}
	return (after_split);
}

void	arg_free(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr_dest;

	ptr_dest = dest;
	while (*ptr_dest)
		ptr_dest++;
	while (*src)
	{
		*ptr_dest = *src;
		ptr_dest++;
		src++;
	}
	*ptr_dest = '\0';
	return (dest);
}

void	main_sort(t_list *a)
{
	t_list	*b;

	b = NULL;
	if (!ft_is_sorted(a))
	{
		if (ft_stack_length(a) == 2)
			ft_sa(&a);
		else if (ft_stack_length(a) == 3)
			ft_easy_sort(&a);
		else
			ft_push_swap(&a, &b);
	}
	free_list(&a);
}
