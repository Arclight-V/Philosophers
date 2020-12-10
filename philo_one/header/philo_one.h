/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:20:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/10 17:16:01 by anatashi         ###   ########.fr       */
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
	int			numb_phil;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			ntepme;
}				t_philo_pharam;

int	main(int argc, char **argv);
int	tmp(void);

#endif
