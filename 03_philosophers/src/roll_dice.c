/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll_dice.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:02:14 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/07/20 17:24:23 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <time.h>

pthread_mutex_t	mutex;

void	*roll_dice()
{
	int value;
	int	*result;

	value = (rand() % 6) + 1;
	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	*result = value;
	return ((void *) result);
}

int	main(int argc, char **argv)
{
	pthread_t	th[8];
	int			i;
	int			*res;
	srand(time(NULL));

	(void)argc;
	(void)argv;
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 8)
	{
		if (pthread_create(&th[i], NULL, &roll_dice, NULL) != 0)
		{
			printf("Failed to create thread");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], (void **) &res) != 0)
			return (2);
		printf("Result of th[%d] is %d\n", i, *res);
		i++;
	}
	free(res);
	return (0);
}