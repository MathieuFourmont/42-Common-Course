/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:46:29 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/07/21 16:51:57 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	int	philo_nb;

	philo_nb = *(int *)arg + 1;
	if ((philo_nb % 2) == 0)
		usleep(3);
	printf("%d has taken fork [%d]\n", philo_nb, philo_nb);
	printf("%d has taken fork [%d]\n", philo_nb, philo_nb + 1);
	printf("%d is eating\n", philo_nb);
	free(arg);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int 		nb_philo;
	int			i;
	int			*a;
	pthread_t	th[ft_atoi(argv[1])];

	nb_philo = ft_atoi(argv[1]);
	i = 0;
	while (i < nb_philo)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
		{
			printf("Failed to create thread\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			printf("Failed to join thread\n");
			return (2);
		}
		i++;
	}
	return (0);
}	