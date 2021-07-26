/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_death_and_ntepme.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:43:15 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/05 09:03:37 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void		checking_death(t_philo_two *philo_two, int *loop, int *i,
																long time)
{
	sem_wait(g_wait);
	if (time - philo_two->philo[*i].waiting_time_of_the_fork
								> philo_two->conf->time_die)
	{
		sem_post(g_wait);
		print_message(&philo_two->conf->buf, time_stop(),
							DEAD, philo_two->philo[*i].number);
		g_flag = 0;
		(*i) = -1;
		while (++(*i) < philo_two->conf->numb_phil)
			philo_two->philo[*i].loop = STOP_LOOP - 1;
		(*i) = -1;
		while (++(*i) < philo_two->conf->numb_phil)
		{
			pthread_join(philo_two->all_thread[*i], NULL);
			pthread_detach(philo_two->all_thread[*i]);
		}
		*loop = STOP_LOOP;
	}
	sem_post(g_wait);
}

static void		checking_ntempe(t_philo_two *philo_two, int *loop, int *i)
{
	if (philo_two->conf->count_eating == STOP_LOOP)
	{
		(*i) = -1;
		while (++(*i) < philo_two->conf->numb_phil)
		{
			pthread_join(philo_two->all_thread[*i], NULL);
			pthread_detach(philo_two->all_thread[*i]);
		}
		*loop = STOP_LOOP;
	}
}

void			checking_death_and_ntepme(t_philo_two *philo_two)
{
	int		i;
	int		loop;
	long	time;

	i = -1;
	loop = EXECUTE_LOOP;
	while (loop == EXECUTE_LOOP)
	{
		i = -1;
		time = time_stop();
		while (++i < philo_two->conf->numb_phil)
		{
			checking_death(philo_two, &loop, &i, time);
			checking_ntempe(philo_two, &loop, &i);
		}
	}
}
