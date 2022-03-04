/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:13:32 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 18:28:28 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*ref;

	ref = *stack;
	if (!ref)
		return (0);
	if (!ref->next)
		return (1);
	while (ref->next)
	{
		if (ref->content > ref->next->content)
			return (0);
		ref = ref->next;
	}
	return (1);
}

int	ft_get_min(t_list **stack)
{
	int		min;
	t_list	*ref;

	ref = *stack;
	if (!ref)
		return (INT_MIN);
	min = ref->content;
	while (ref)
	{
		if (ref->content < min)
			min = ref->content;
		ref = ref->next;
	}
	return (min);
}

int	ft_get_max(t_list **stack)
{
	int		max;
	t_list	*ref;

	ref = *stack;
	if (!ref)
		return (INT_MAX);
	max = ref->content;
	while (ref)
	{
		if (ref->content > max)
			max = ref->content;
		ref = ref->next;
	}
	return (max);
}

int	ft_get_max_bits(t_list **stack)
{
	int		max;
	int		max_bits;
	t_list	*ref;

	ref = *stack;
	max = ref->index;
	max_bits = 0;
	while (ref)
	{
		if (ref->index > max)
			max = ref->index;
		ref = ref->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
