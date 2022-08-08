/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:29:43 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/07/28 12:43:23 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* When there's an odd number of philosophers, we run into race condition.
 * Meaning, at some point the philosophers that manage to get hold of the forks
 * may not include the one who didn't eat the earliest.
 * The solution? Add a small mandatory thinking time, to give priority to the
 * one who has been thinking the longest.
 * This should be time_to_eat - time_to_slep + small_buffer.
 */
void	thinking(t_philo *philo)
{
	long long	start_thinking;

	if (check_ending_conditions(philo))
		return ;
	start_thinking = gettimeofday_ms();
	print_message(philo, start_thinking, THINKING);
	if (philo->config->philo_nb % 2 != 0)
	{
		if (philo->config->eating_time > philo->config->sleeping_time)
			usleep((philo->config->eating_time - philo->config->sleeping_time) * 1000);
		usleep(1000);
	}
	take_forks(philo);
}

void	sleeping(t_philo *philo)
{
	long long	start_sleeping;

	if (check_ending_conditions(philo))
		return ;
	start_sleeping = gettimeofday_ms();
	print_message(philo, start_sleeping, SLEEPING);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->left_fork->taken = 0;
	philo->right_fork->taken = 0;
	while (gettimeofday_ms() < start_sleeping + philo->config->sleeping_time)
	{
		if (check_ending_conditions(philo))
			return ;
	}
	thinking(philo);
}

void	eating(t_philo *philo)
{
	long long	start_eating;

	if (check_ending_conditions(philo))
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return ;
	}
	start_eating = gettimeofday_ms();
	philo->death_certificate = start_eating + philo->config->time_to_die;
	print_message(philo, start_eating, EATING);
	while (gettimeofday_ms() < start_eating + philo->config->eating_time)
	{
		if (check_ending_conditions(philo))
		{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return ;
		}
	}
	if (philo->config->max_meals_defined)
		philo->config->nb_meals[philo->position - 1] += 1;
	sleeping(philo);
}

void	take_forks(t_philo *philo)
{
	long long	time_at_taking;

	if (check_ending_conditions(philo))
		return ;
	while (!philo->left_fork || philo->left_fork->taken || philo->right_fork->taken)
	{
		if (check_ending_conditions(philo))
			return ;
	}
	philo->left_fork->taken = 1;
	philo->right_fork->taken = 1;
	pthread_mutex_lock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
	time_at_taking = gettimeofday_ms();
	print_message(philo, time_at_taking, L_FORK);
	print_message(philo, time_at_taking, R_FORK);
	eating(philo);
}