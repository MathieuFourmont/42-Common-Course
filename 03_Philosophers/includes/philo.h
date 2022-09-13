/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:19:59 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:58 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <stdbool.h>

/*
** -------------------------- STRUCT DECLARATION --------------------------
*/

typedef struct s_philo	t_philo;
typedef struct s_config	t_config;

typedef enum s_status
{
	TAKE_FORK = 1,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef struct s_config
{
	t_philo			*philo;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	int				philo_nb;
	size_t			e_time;
	size_t			s_time;
	size_t			time_to_die;
	size_t			start_time;
	int				max_nb_of_meals;
	bool			the_end;
}	t_config;

typedef struct s_philo
{
	pthread_t		th;
	int				position;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	size_t			last_meal;
	int				meals_nb;
	bool			the_end;
	t_config		*config;
}	t_philo;

/*
** ------------------------------ PROTOTYPES ------------------------------
*/

int		ft_atoi(const char *nptr);
int		str_is_digit(char *str);
size_t	gettimeofday_ms(void);
void	ft_usleep(size_t ms, t_config *config);
int		init_config(t_config *config, char **argv);
void	print_message(t_philo *philo, char *action);
int		check_args(int argc, char **argv);
int		all_philos_are_full(t_config *config);
void	check_death(t_config *config);

#endif