/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:19:59 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/08/08 13:26:31 by mmaxime-         ###   ########.fr       */
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

/*
** -------------------------- STRUCT DECLARATION --------------------------
*/

typedef enum s_status
{
	L_FORK = 1,
	R_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef struct s_config
{
	int				philo_nb;
	int				e_time;
	int				s_time;
	int				time_to_die;
	int				max_nb_of_meals;
	int				max_meals_defined;
	int				*nb_meals;
	int				the_end;
	int				printed_last_words;
	pthread_mutex_t	*print_mutex;
	long long		start_time;
}	t_config;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;
	int				taken;
}	t_fork;

typedef struct s_philo
{
	int			position;
	t_config	*config;
	t_fork		*left_fork;
	t_fork		*right_fork;
	long long	death_certificate;
}	t_philo;

/*
** ------------------------------ PROTOTYPES ------------------------------
*/

int			ft_atoi(const char *nptr);
int			str_is_digit(char *str);
void		ft_error(char *str);
t_config	*init_config(int argc, char **argv);
int			set_config(t_config *config, pthread_mutex_t *print_mutex);
t_fork		*init_forks(int philo_nb);
t_philo		*init_philos(t_config *config, t_fork *forks);
int			create_threads(t_config *config, t_philo *philo);
void		ft_clean(t_config *config, t_fork *forks, t_philo *philos);
int			ft_clean_thread(pthread_t *th);
long long	gettimeofday_ms(void);
void		print_message(t_philo *philo, long long time, t_status status);
int			all_philos_are_full(t_philo *philo);
int			someone_died(t_philo *philo);
int			check_ending_conditions(t_philo *philo);
void		checks_args(int argc, char **argv);
void		thinking(t_philo *philo);
void		sleeping(t_philo *philo);
void		eating(t_philo *philo);
void		take_forks(t_philo *philo);

#endif