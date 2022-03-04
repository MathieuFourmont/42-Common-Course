/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:55:37 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 18:15:19 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_init(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 5)
		small_sort(a, b);
	else
		radix_sort(a, b);
}

void	ft_clear_stacks(t_list **a, t_list **b)
{
	t_list	*tmp;

	while (*a != NULL)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
	}
	while (*b != NULL)
	{
		tmp = *b;
		(*b) = (*b)->next;
		free(tmp);
	}
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc < 2)
		return (1);
	ft_check(argc, argv);
	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	if (!a || !b)
		return (1);
	*a = NULL;
	*b = NULL;
	ft_stack_init(a, argc, argv);
	if (ft_is_sorted(a))
	{
		ft_clear_stacks(a, b);
		return (0);
	}
	sort_stack(a, b);
	ft_clear_stacks(a, b);
	return (0);
}
