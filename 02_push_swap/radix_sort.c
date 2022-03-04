/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:24:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 17:31:51 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **a, t_list **b)
{
	int		bit;
	int		pos;
	int		size;
	int		max_bits;
	t_list	*ref_a;

	bit = 0;
	ref_a = *a;
	size = ft_lstsize(ref_a);
	max_bits = ft_get_max_bits(a);
	while (bit < max_bits)
	{
		pos = 0;
		while (pos++ < size)
		{
			ref_a = *a;
			if (((ref_a->index >> bit) & 1) == 1)
				ra(a);
			else
				pb(b, a);
		}
		while (ft_lstsize(*b) != 0)
			pa(a, b);
		bit++;
	}
}
