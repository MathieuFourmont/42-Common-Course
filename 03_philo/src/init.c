/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:16:47 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/07/28 14:50:57 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_fork	*init_forks(int philo_nb)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * philo_nb);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < philo_nb)
	{
		forks[i].id = i + 1;
		pthread_mutex_init(&forks[i].mutex, NULL);
		forks[i].taken = 0;
		i++;
	}
	return (forks);
}

t_philo	*init_philos(t_config *config, t_fork *forks)
{
	t_philo	*philos;
	int		i;

	if (!forks)
		return (NULL);
	philos = (t_philo *)malloc(sizeof(t_philo) * config->philo_nb);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < config->philo_nb)
	{
		philos[i].position = i + 1;
		if (config->philo_nb == 1)
			philos[i].left_fork = NULL;
		else if (i == 0)
			philos[i].left_fork = &forks[config->philo_nb - 1]; // fork[philo_nb].id = philo_nb + 1;
		else
			philos[i].left_fork = &forks[i - 1];
		philos[i].right_fork = &forks[i];
		philos[i].config = config;
		i++;
	}
	return (philos);
}

int	set_config(t_config *config, pthread_mutex_t *print_mutex)
{
	int	i;

	config->the_end = 0;
	config->printed_last_words = 0;
	pthread_mutex_init(print_mutex, NULL);
	config->print_mutex = print_mutex;
	config->nb_meals = (int *)malloc(sizeof(int) * config->philo_nb);
	if (!config->nb_meals)
		return (0);
	i = 0;
	while (i < config->philo_nb)
	{
		config->nb_meals[i] = 0;
		i++;
	}
	return (1);
}

t_config	*init_config(int argc, char **argv)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config)); //to free
	if (!config)
		return (NULL);
	config->philo_nb = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->eating_time = ft_atoi(argv[3]);
	config->sleeping_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		config->max_meals_defined = 1;
		config->max_nb_of_meals = ft_atoi(argv[5]);
	}
	else
		config->max_meals_defined = 0;
	return (config);
}