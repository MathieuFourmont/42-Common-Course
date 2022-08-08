/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:25:43 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/08/08 13:17:00 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_philo *philo, long long time, t_status status)
{
	int	timestamp;

	if (philo->config->printed_last_words == 1)
		return ;
	if (philo->config->the_end == 1 && status == DEAD)
		philo->config->printed_last_words = 1;
	pthread_mutex_lock(philo->config->print_mutex);
	timestamp = (int)time - philo->config->start_time;
	printf("%d %d ", timestamp, philo->position);
	if (status == DEAD)
		printf("died\n");
	else if (status == R_FORK)
		printf("has taken a fork\n");
	else if (status == L_FORK)
		printf("has taken a fork\n");
	else if (status == EATING)
		printf("is eating\n");
	else if (status == SLEEPING)
		printf("is sleeping\n");
	else if (status == THINKING)
		printf("is thinking\n");
	pthread_mutex_unlock(philo->config->print_mutex);
}

int	all_philos_are_full(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config->philo_nb)
	{
		if (philo->config->nb_meals[i] < philo->config->max_nb_of_meals)
			return (0);
		i++;
	}
	philo->config->the_end = 1;
	return (1);
}

int	someone_died(t_philo *philo)
{
	long long	check_time;

	check_time = gettimeofday_ms();
	if (philo->death_certificate <= check_time)
	{
		philo->config->the_end = 1;
		usleep(1000);
		print_message(philo, check_time, DEAD);
		return (1);
	}
	return (0);
}

int	check_ending_conditions(t_philo *philo)
{
	if (philo->config->the_end == 1)
		return (1);
	if (someone_died(philo))
		return (1);
	if (!philo->config->max_meals_defined)
		return (0);
	if (all_philos_are_full(philo))
		return (1);
	return (0);
}

void	checks_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!str_is_digit(argv[i]))
			ft_error("Error: at least one arg is not an int");
		i++;
	}
}
