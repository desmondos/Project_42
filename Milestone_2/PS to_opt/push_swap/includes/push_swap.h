/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:40:36 by candriam          #+#    #+#             */
/*   Updated: 2024/06/29 15:16:32 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_list
{
	struct s_list	*prev;
	bool			pre_mid;
	bool			is_cheapest;
	int				data;
	int				cur_pos;
	int				fin_pos;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}				t_list;

bool	ft_is_sorted(t_list *a);

long	ft_atolong(const char *nptr);

char	**ft_split(char const *s, char c);

t_list	*ft_is_higher(t_list *a);
t_list	*find_min(t_list *a);
t_list	*return_cheap(t_list *list);
t_list	*ft_lastlst(t_list *list);

int		ft_is_mid_nbr(t_list **a);
int		ft_input_error(char *input);
int		ft_atoi(const char *nptr);
int		ft_stack_length(t_list *a);
int		ft_is_dup(t_list *a, int input);
int		main(int argc, char *argv[]);
int		ft_is_lowest(t_list *a);

void	main_sort(t_list *a);
void	ft_rotate(t_list **stack);
void	ft_setup_pos(t_list *stack);
void	ft_setup_target(t_list *a, t_list *b);
void	ft_set_cur(t_list *a);
void	ft_rot_b(t_list **b, t_list *top);
void	ft_rot_a(t_list **b, t_list *top);
void	ft_moves(t_list **a, t_list **b);
void	ft_rot(t_list **a, t_list *top);
void	ft_init_nodes(t_list *a, t_list *b);
void	ft_set_cost(t_list *a, t_list *b);
void	ft_set_cheapest(t_list *b);
void	ft_push_swap(t_list **a, t_list **b);
void	ft_sa(t_list **a);
void	ft_sb(t_list **b);
void	ft_ss(t_list **a, t_list **b);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **b, t_list **a);
void	ft_easy_sort(t_list **a);
void	ft_addback(t_list **stack, int input);
void	ft_ra(t_list **a);
void	ft_rb(t_list **b);
void	ft_rr(t_list **a, t_list **b);
void	rot_all(t_list **a, t_list **b, t_list *cheap);
void	rev_rot_all(t_list **a, t_list **b, t_list *cheap);
void	ft_set_top(t_list **a);
void	ft_mid_sort(t_list **a, t_list **b);
void	ft_rra(t_list **a);
void	ft_rrb(t_list **b);
void	ft_rrr(t_list **a, t_list **b);
void	ft_init(t_list **a, char *argv[]);
void	ft_puterror(void);
void	print_stack(t_list **pile);

#endif
