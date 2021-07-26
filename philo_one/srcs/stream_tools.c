/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:15:00 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/29 12:52:05 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	checking_the_first_fork_wait(int *i, long *waiting_time_of_the_fork)
{
	if (!*i)
	{
		pthread_mutex_lock(&g_wait);
		*waiting_time_of_the_fork = time_stop();
		pthread_mutex_unlock(&g_wait);
		(*i)++;
	}
}

void	taken_forks(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	pthread_mutex_lock(p->right_fork);
	print_message(&p->conf->buf, time_stop(), TAKEN_FORK, p->number);
	print_message(&p->conf->buf, time_stop(), TAKEN_FORK, p->number);
}

void	eating(t_philo *p, long time)
{
	time = time_stop();
	print_message(&p->conf->buf, time, EATING, p->number);
	pthread_mutex_lock(&g_wait);
	p->waiting_time_of_the_fork = time;
	pthread_mutex_unlock(&g_wait);
	usleep(p->conf->time_eat * 1000);
}

void	sleeping(t_philo *p)
{
	print_message(&p->conf->buf, time_stop(), SLEEP, p->number);
	usleep(p->conf->time_sleep * 1000);
}

void	put_down_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}
