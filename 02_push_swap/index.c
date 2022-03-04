/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:36:23 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 18:23:30 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_next_min(t_list **stack)
{
	t_list	*ref;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	ref = *stack;
	if (ref)
	{
		while (ref)
		{
			if ((ref->index == -1) && (!has_min || ref->content < min->content))
			{
				min = ref;
				has_min = 1;
			}
			ref = ref->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	int		index;
	t_list	*ref;

	index = 0;
	ref = ft_next_min(stack);
	while (ref)
	{
		ref->index = index++;
		ref = ft_next_min(stack);
	}
}
