/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:06:41 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/09 12:51:51 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*top_b;

	if (*b == NULL || b == NULL)
		return (NULL);
	top_b = *b;
	*b = top_b->next;
	if (a == NULL)
		return ;
	ft_lstadd_front(a, top_b);
	ft_lstdelone(top_b, NULL);
}

void	pb(t_list **b, t_list **a)
{
	t_list	*top_a;

	if (*a == NULL || a == NULL)
		return (NULL);
	top_a = *a;
	*a = top_a->next;
	if (b == NULL)
		return (NULL);
	ft_lstadd_front(b, top_a);
	ft_lstdelone(top_a, NULL);
}
