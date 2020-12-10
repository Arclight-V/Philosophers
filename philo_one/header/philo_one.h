/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:20:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/10 17:43:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/*
** numb_phil  - number_of_philosopher
** time_die   - time to die
** time_eat   - time to eat
** time_sleep - time to sleep
** ntepme	  - [umber_of_times_each_philosopher_must_eat]
*/

typedef	struct	s_philo_pharam
{
	size_t		numb_phil;
	size_t		time_die;
	size_t		time_eat;
	size_t		time_sleep;
	size_t		ntepme;
}				t_philo_pharam;

int	main(int argc, char **argv);
int	tmp(void);

#endif
