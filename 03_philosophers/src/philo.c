/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:46:29 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/08/11 18:42:01 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	take_forks(philo);
	return (NULL);
}

int	run_philo(t_config *config, t_philo *philos)
{
	int			i;
	pthread_t	*th;

	i = 0;
	th = (pthread_t *)malloc(sizeof(pthread_t) * config->philo_nb);
	if (!th)
		return (1);
	config->start_time = gettimeofday_ms();
	while (i < config->philo_nb)
	{
		philos[i].death_certificate = config->start_time + config->time_to_die;
		if (pthread_create(&th[i], NULL, &routine, &philos[i]) != 0)
			return (ft_clean_thread(th));
		i++;
	}
	i = 0;
	while (i < config->philo_nb)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (ft_clean_thread(th));
	}
	free(th);
	return (0);
}

int	main(int argc, char **argv)
{
	t_config		*config;
	pthread_mutex_t	print_mutex;
	t_fork			*forks;
	t_philo			*philos;
	int				res;

	if (check_args(argc, argv))
		return (1);
	config = init_config(argc, argv);
	if (!config)
		return (1);
	if (set_config(config, &print_mutex))
	{
		forks = init_forks(config->philo_nb);
		philos = init_philos(config, forks);
		res = 1;
		if (forks && philos)
			res = run_philo(config, philos);
		ft_clean(config, forks, philos);
		return (res);
	}
	ft_clean(config, NULL, NULL);
	return (1);
}
