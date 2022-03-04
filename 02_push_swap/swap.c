/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:47:40 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 18:39:48 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*nb1;
	t_list	*nb2;
	int		tmp_content;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return ;
	nb1 = *stack;
	nb2 = nb1->next;
	tmp_content = nb1->content;
	tmp_index = nb1->index;
	nb1->content = nb2->content;
	nb1->index = nb2->index;
	nb2->content = tmp_content;
	nb2->index = tmp_index;
}

void	sa(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		ft_swap(a);
		ft_swap(b);
		write(1, "ss\n", 3);
	}
}
