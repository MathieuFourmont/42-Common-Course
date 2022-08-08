/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:22:15 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/08/08 13:24:03 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

int	ft_clean_thread(pthread_t *th)
{
	free(th);
	return (1);
}
