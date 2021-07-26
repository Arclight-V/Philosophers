/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_death_and_ntepme.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:43:15 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/05 09:02:27 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		checking_death(t_philo_one *philo_one, int *loop, int *i,
																	long time)
{
	pthread_mutex_lock(&g_wait);
	if (time - philo_one->philo[*i].waiting_time_of_the_fork
													> philo_one->conf->time_die)
	{
		pthread_mutex_unlock(&g_wait);
		print_message(&philo_one->conf->buf, time_stop(),
							DEAD, philo_one->philo[*i].number);
		g_flag = 0;
		(*i) = -1;
		while (++(*i) < philo_one->conf->numb_phil)
			philo_one->philo[*i].loop = STOP_LOOP + 1;
		(*i) = -1;
		while (++(*i) < philo_one->conf->numb_phil)
		{
			pthread_join(philo_one->all_thread[*i], NULL);
			pthread_detach(philo_one->all_thread[*i]);
		}
		*loop = STOP_LOOP;
	}
	pthread_mutex_unlock(&g_wait);
}

static void		checking_ntempe(t_philo_one *philo_one, int *loop, int *i)
{
	if (philo_one->conf->count_eating == STOP_LOOP)
	{
		(*i) = -1;
		while (++(*i) < philo_one->conf->numb_phil)
		{
			pthread_join(philo_one->all_thread[*i], NULL);
			pthread_detach(philo_one->all_thread[*i]);
		}
		*loop = STOP_LOOP;
	}
}

void			checking_death_and_ntepme(t_philo_one *philo_one)
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
		while (++i < philo_one->conf->numb_phil)
		{
			checking_death(philo_one, &loop, &i, time);
			checking_ntempe(philo_one, &loop, &i);
		}
	}
}
