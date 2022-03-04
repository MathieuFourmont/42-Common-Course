/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:33:30 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/14 16:10:41 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	t_list	*final_nb;
	t_list	*before_final_nb;

	if (ft_lstsize(*stack) > 1)
	{
		before_final_nb = *stack;
		final_nb = before_final_nb;
		while (final_nb->next)
			final_nb = final_nb->next;
		while (before_final_nb->next->next)
			before_final_nb = before_final_nb->next;
		before_final_nb->next = NULL;
		final_nb->next = *stack;
		*stack = final_nb;
	}
}

void	rra(t_list **a)
{
	if (*a && ft_lstsize(*a) > 1)
	{
		ft_rev_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **b)
{
	if (*b && ft_lstsize(*b) > 1)
	{
		ft_rev_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **a, t_list **b)
{
	if (*a && ft_lstsize(*a) > 1 && *b && ft_lstsize(*b) > 1)
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
		write(1, "rrr\n", 4);
	}
}
