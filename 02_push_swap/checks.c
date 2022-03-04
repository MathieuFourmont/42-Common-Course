/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:06:38 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 16:13:50 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int	ft_isduplicate(int current_arg, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == current_arg)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isint(char *current_arg)
{
	int	i;

	i = 0;
	if (current_arg[0] == '-')
		i++;
	while (current_arg[i])
	{
		if (!ft_isdigit(current_arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check(int argc, char **argv)
{
	int		i;
	long	value;
	char	**args;

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
		value = ft_atoi(args[i]);
		if (ft_isduplicate(value, args, i))
			ft_error("Error");
		if (!ft_isint(args[i]))
			ft_error("Error");
		if (value < INT_MIN || value > INT_MAX)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
