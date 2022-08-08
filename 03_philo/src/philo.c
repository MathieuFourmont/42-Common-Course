/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:46:29 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/07/28 14:47:30 by miam             ###   ########.fr       */
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
	th = (pthread_t *)malloc(sizeof(pthread_t) * config->philo_nb); //to free
	if (!th)
		return (1);
	config->start_time = gettimeofday_ms();
	while (i < config->philo_nb)
	{
		philos[i].death_certificate = config->start_time + config->time_to_die;
		if (pthread_create(&th[i], NULL, &routine, &philos[i]) != 0)
		{
			free(th);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < config->philo_nb)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			free(th);
			return (1);
		}
	}
	free(th);
	return (0);
}

int	main(int argc, char **argv)
{
	t_config		*config;
	int				i;
	pthread_mutex_t	print_mutex;
	t_fork			*forks;
	t_philo			*philos;
	int				res;

	if (argc < 5 || argc > 6)
		ft_error("Error: usage: ./philo arg1 arg2 arg3 arg4 [arg5](optionnal)");
	i = 1;
	while (i < argc)
	{
		if (!str_is_digit(argv[i]))
			ft_error("Error: all the args are not int");
		i++;
	}	
	config = init_config(argc, argv); // to init the nb of th and forks needed and set the different times
	if (!config)
		return (1);
	if(set_config(config, &print_mutex))
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