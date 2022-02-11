/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:47:40 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/09 14:19:01 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*nb1;
	t_list	*nb2;
	t_list	*nb3;

	nb1 = *stack;
	nb2 = *stack->next;
	nb3 = nb2->next;
	*stack = nb2;
	nb2->next = nb1;
	nb1->next = nb3;
}

void	sa(t_list **a)
{
	if (ft_lstsize(*a) > 1)
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **b)
{
	if (ft_lstsize(*b) > 1)
	{
		ft_swap(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1)
		ft_swap(a);
	if (ft_lstsize(*b) > 1)
		ft_swap(b);
	write(1, "ss\n", 3);
}
