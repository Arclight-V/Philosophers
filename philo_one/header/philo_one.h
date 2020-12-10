/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:20:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/10 18:56:27 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR_1 "ERROR: invalid number of arguments. should be 5 of 6.\n"
# define ERROR_2 "ERROR: number of philosophers must be positive number\n"
/*
** numb_phil  - number_of_philosopher
** time_die   - time to die
** time_eat   - time to eat
** time_sleep - time to sleep
** ntepme	  - [number_of_times_each_philosopher_must_eat]
*/

typedef	struct	s_philo_pharam
{
	long long	numb_phil;
	long long	time_die;
	long long	time_eat;
	long long	time_sleep;
	long long	ntepme;
}				t_philo_pharam;

int	main(int argc, char **argv);
int	tmp(void);

#endif
