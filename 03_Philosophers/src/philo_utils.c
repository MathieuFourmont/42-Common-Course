/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:39:37 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/09/07 18:02:08 by mmaxime-         ###   ########.fr       */
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
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

size_t	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void	ft_usleep(size_t ms, t_config *config)
{
	size_t	start;

	start = gettimeofday_ms();
	while (gettimeofday_ms() - start < ms)
	{
		pthread_mutex_lock(&config->print_mutex);
		if (config->the_end == true)
		{
			pthread_mutex_unlock(&config->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&config->print_mutex);
		if (config->philo_nb < 100)
			usleep(100);
		else
			usleep(1000);
	}
}
