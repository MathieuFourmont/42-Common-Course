/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:07:30 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 17:47:45 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include "libft/libft.h"
/*# include "ft_printf.h"*/
# include <limits.h>

/*
** ------------------------------ PROTOTYPES ------------------------------
*/

// ACTIONS
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// STACK FUNCTIONS
void	ft_error(char *s);
void	ft_free(char **ptr);
int		ft_isduplicate(int current_arg, char **argv, int i);
int		ft_isint(char *current_arg);
void	ft_check(int argc, char **argv);
int		ft_is_sorted(t_list **stack);
int		ft_get_min(t_list **stack);
int		ft_get_max(t_list **stack);
int		ft_get_max_bits(t_list **stack);
void	index_stack(t_list **stack);
t_list	*ft_next_min(t_list **stack);

// SORTING
void	radix_sort(t_list **a, t_list **b);
void	sort_stack_3(t_list **a);
void	sort_stack_4(t_list **a, t_list **b);
void	sort_stack_5(t_list **a, t_list **b);
void	small_sort(t_list **a, t_list **b);

#endif
