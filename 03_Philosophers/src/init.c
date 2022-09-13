/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:16:47 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/09/07 18:00:47 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_philos(t_config *config)
{
	int		i;

	i = 0;
	memset(config->philo, 0, sizeof(t_philo) * config->philo_nb);
	while (i < config->philo_nb)
	{
		config->philo[i].position = i + 1;
		config->philo[i].config = config;
		config->philo[i].left_fork = &config->forks[i];
		if (i == config->philo_nb - 1)
			config->philo[i].right_fork = &config->forks[0];
		else
			config->philo[i].right_fork = &config->forks[i + 1];
		i++;
	}
}

static int	init_mutexes(t_config *config)
{
	int	i;

	i = 0;
	memset(config->forks, 0, sizeof(pthread_mutex_t) * config->philo_nb);
	while (i < config->philo_nb)
	{
		if (pthread_mutex_init(&config->forks[i], NULL))
			break ;
		i++;
	}
	if (i != config->philo_nb || pthread_mutex_init(&config->print_mutex, NULL))
	{
		while (i >= 0)
		{
			pthread_mutex_destroy(&config->forks[i]);
			i--;
		}
		free(config->philo);
		free(config->forks);
		return (0);
	}
	return (1);
}

int	init_config(t_config *config, char **argv)
{
	memset(config, 0, sizeof(t_config));
	config->philo_nb = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->e_time = ft_atoi(argv[3]);
	config->s_time = ft_atoi(argv[4]);
	if (argv[5])
		config->max_nb_of_meals = ft_atoi(argv[5]);
	config->philo = malloc(sizeof(t_philo) * config->philo_nb);
	config->forks = malloc(sizeof(pthread_mutex_t) * config->philo_nb);
	if (!config->philo || !config->forks)
	{
		free(config->philo);
		free(config->forks);
		return (0);
	}
	if (!init_mutexes(config))
		return (0);
	init_philos(config);
	return (1);
}
