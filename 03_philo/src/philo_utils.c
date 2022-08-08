/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:39:37 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/07/28 11:26:03 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb * sign);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57 )
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (1);
}

long long	gettimeofday_ms()
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_clean(t_config *config, t_fork *forks, t_philo *philos)
{
	int	i;

	if (philos)
		free(philos);
	if (forks)
	{
		i = 0;
		while (i < config->philo_nb)
		{
			pthread_mutex_destroy(&forks[i].mutex);
			i++;
		}
		free(forks);
	}
	if (config)
	{
		pthread_mutex_destroy(config->print_mutex);
		free(config);
	}
}
