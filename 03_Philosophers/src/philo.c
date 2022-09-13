/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:46:29 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/09/07 18:56:31 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	do_action(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->config->print_mutex);
	if (philo->config->the_end)
	{
		pthread_mutex_unlock(&philo->config->print_mutex);
		return (1);
	}
	if (action == EATING)
	{
		print_message(philo, "is eating");
		philo->last_meal = gettimeofday_ms();
	}
	else if (action == TAKE_FORK)
		print_message(philo, "has taken a fork");
	else if (action == SLEEPING)
	{
		print_message(philo, "is sleeping");
		philo->meals_nb += 1;
		if (philo->meals_nb == philo->config->max_nb_of_meals)
			all_philos_are_full(philo->config);
	}
	else if (action == THINKING)
		print_message(philo, "is thinking");
	pthread_mutex_unlock(&philo->config->print_mutex);
	return (0);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->position % 2 == 0)
		ft_usleep(philo->config->e_time / 2, philo->config);
	while (philo->the_end == false)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->the_end = do_action(philo, TAKE_FORK);
		if (philo->left_fork == philo->right_fork)
			break ;
		pthread_mutex_lock(philo->right_fork);
		philo->the_end = do_action(philo, TAKE_FORK);
		philo->the_end = do_action(philo, EATING);
		ft_usleep(philo->config->e_time, philo->config);
		philo->the_end = do_action(philo, SLEEPING);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_usleep(philo->config->s_time, philo->config);
		philo->the_end = do_action(philo, THINKING);
	}
	if (philo->left_fork == philo->right_fork)
		pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

static int	run_philo(t_config *config)
{
	int	i;

	i = 0;
	config->start_time = gettimeofday_ms();
	while (i < config->philo_nb)
	{
		config->philo[i].last_meal = config->start_time;
		if (pthread_create(&config->philo[i].th
				, NULL, &routine, &config->philo[i]) != 0)
		{
			pthread_mutex_lock(&config->print_mutex);
			config->the_end = true;
			pthread_mutex_unlock(&config->print_mutex);
			return (0);
		}
		i++;
	}
	check_death(config);
	return (1);
}

static void	clean_config(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->philo_nb)
	{
		pthread_join(config->philo[i].th, NULL);
		i++;
	}
	free (config->philo);
	i = 0;
	while (i < config->philo_nb)
	{
		pthread_mutex_destroy(&config->forks[i]);
		i++;
	}
	free(config->forks);
	pthread_mutex_destroy(&config->print_mutex);
}

int	main(int argc, char **argv)
{
	t_config	config;

	if (check_args(argc, argv))
		return (1);
	if (!init_config(&config, argv))
		return (2);
	if (!run_philo(&config))
	{
		clean_config(&config);
		return (3);
	}
	clean_config(&config);
	return (0);
}
