/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:25:43 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/09/07 18:51:46 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_philo *philo, char *action)
{
	size_t	timestamp;

	timestamp = gettimeofday_ms() - philo->config->start_time;
	printf("%04zu %d %s\n", timestamp, philo->position, action);
}

int	all_philos_are_full(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->philo_nb)
	{
		if (config->philo[i].meals_nb < config->max_nb_of_meals)
			return (0);
		i++;
	}
	config->the_end = true;
	return (1);
}

void	check_death(t_config *config)
{
	size_t	check_time;
	int		i;

	while (1)
	{
		i = 0;
		pthread_mutex_lock(&config->print_mutex);
		check_time = gettimeofday_ms();
		while (i < config->philo_nb)
		{
			if (check_time - config->philo[i].last_meal >= config->time_to_die)
			{
				print_message(&config->philo[i], "died");
				config->the_end = true;
				break ;
			}
			i++;
		}
		if (config->the_end == true)
		{
			pthread_mutex_unlock(&config->print_mutex);
			return ;
		}
		pthread_mutex_unlock(&config->print_mutex);
	}
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philos [# Philosophers] [time_to_die] [time_to_eat] ");
		printf("[time_to_sleep] ([times_each_philosopher_must_eat])\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!str_is_digit(argv[i]) || ft_atoi(argv[i]) == 0)
		{
			printf("Error: Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}
