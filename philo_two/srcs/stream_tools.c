/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:15:00 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/28 23:00:53 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	checking_the_first_fork_wait(int *i, long *waiting_time_of_the_fork)
{
	if (!*i)
	{
		sem_wait(g_wait);
		*waiting_time_of_the_fork = time_stop();
		sem_post(g_wait);
		(*i)++;
	}
}

void	taken_forks(t_philo *p)
{
	sem_wait(g_wait_fork);
	sem_wait(p->forks);
	sem_wait(p->forks);
	sem_post(g_wait_fork);
	print_message(&p->conf->buf, time_stop(), TAKEN_FORK, p->number);
	print_message(&p->conf->buf, time_stop(), TAKEN_FORK, p->number);
}

void	eating(t_philo *p, long time)
{
	time = time_stop();
	print_message(&p->conf->buf, time, EATING, p->number);
	sem_wait(g_wait);
	p->waiting_time_of_the_fork = time;
	sem_post(g_wait);
	usleep(p->conf->time_eat * 1000);
}

void	sleeping(t_philo *p)
{
	print_message(&p->conf->buf, time_stop(), SLEEP, p->number);
	usleep(p->conf->time_sleep * 1000);
}

void	put_down_forks(t_philo *p)
{
	sem_post(p->forks);
	sem_post(p->forks);
}
