/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:52:41 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/09 15:28:29 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*top_nb;
	t_list	*final_nb;

	top_nb = *stack;
	final_nb = top_nb;
	while (final_nb->next)
		final_nb = final_nb->next;
	*stack = top_nb->next;
	final_nb->next = top_nb;
	top_nb->next = NULL;
}

void	ra(t_list **a)
{
	if (*a && ft_lstsize(*a) > 1)
	{
		ft_rotate(a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **b)
{
	if (*b && ft_lstsize(*b) > 1)
	{
		ft_rotate(b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **a, t_list **b)
{
	if (*a && ft_lstsize(*a) > 1 && *b && ft_lstsize(*b) > 1)
	{
		ft_rotate(a);
		ft_rotate(b);
		write(1, "rr\n", 3);
	}
}
