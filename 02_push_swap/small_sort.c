/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:56:17 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 16:31:40 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3(t_list **a)
{
	int	min;
	int	max;

	while (!ft_is_sorted(a))
	{
		min = ft_get_min(a);
		max = ft_get_max(a);
		if ((*a)->content == max && (*a)->next->content == min)
			ra(a);
		else if (((*a)->content < (*a)->next->content)
			&& (*a)->next->next->content == min)
			rra(a);
		else
			sa(a);
	}
}

void	sort_stack_4(t_list **a, t_list **b)
{
	int		min;

	min = ft_get_min(a);
	if ((*a)->content != min)
	{
		if ((*a)->next->content == min)
			sa(a);
		else if ((*a)->next->next->content == min)
		{
			ra(a);
			ra(a);
		}
		else
			rra(a);
	}
	if (ft_is_sorted(a))
		return ;
	pb(b, a);
	sort_stack_3(a);
	pa(a, b);
}

void	sort_stack_5(t_list **a, t_list **b)
{
	int		min;

	min = ft_get_min(a);
	if ((*a)->next->content == min)
		ra(a);
	else if ((*a)->next->next->content == min)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->content == min)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next->content == min)
		rra(a);
	if (ft_is_sorted(a))
		return ;
	pb(b, a);
	sort_stack_4(a, b);
	pa(a, b);
}

void	small_sort(t_list **a, t_list **b)
{
	if (ft_is_sorted(a) || ft_lstsize(*a) <= 1)
		return ;
	else if (ft_lstsize(*a) <= 3)
		sort_stack_3(a);
	else if (ft_lstsize(*a) == 4)
		sort_stack_4(a, b);
	else
		sort_stack_5(a, b);
}
