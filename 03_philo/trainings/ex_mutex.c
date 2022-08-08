/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:20:20 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/07/21 13:46:58 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int				mails = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		// everything that is inside mutex_lock/unlock will be protected from other threads executing it at the same time
		mails++;
		pthread_mutex_unlock(&mutex);
		// read mails
		// increment
		// write mails	
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	pthread_t	th[8];
	int			i;

	(void)argc;
	(void)argv;
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 8)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
		{
			printf("Failed to create thread");
			return (1);
		}
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)// eq to "wait" for thread
			return (2);
		printf("Thread %d has finished execution\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}*/