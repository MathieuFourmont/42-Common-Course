/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:19:59 by miam              #+#    #+#             */
/*   Updated: 2022/07/11 15:51:24 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <semaphore.h>

/*
** -------------------------- STRUCT DECLARATION --------------------------
*/

void	*routine();

/*
** ------------------------------ PROTOTYPES ------------------------------
*/


#endif