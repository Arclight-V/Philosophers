/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:49 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:24:55 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		*stream2(void *data)
{
	t_philo *p;
	int		i;
	long	time;

	i = 0;
	time = 0;
	p = (t_philo *)data;
	p->loop = p->conf->ntepme;
	while (p->loop != STOP_LOOP)
	{
		print_message(&p->conf->buf, time_stop(), THINK, p->number);
		checking_the_first_fork_wait(&i, &p->waiting_time_of_the_fork);
		taken_forks(p);
		eating(p, time);
		put_down_forks(p);
		--p->conf->count_eating;
		--p->loop;
		if (p->loop == STOP_LOOP)
			break ;
		sleeping(p);
	}
	return (NULL);
}

static void		*stream(void *data)
{
	t_philo *p;
	int		i;
	long	time;

	i = 0;
	time = 0;
	p = (t_philo *)data;
	while (p->loop == EXECUTE_LOOP)
	{
		print_message(&p->conf->buf, time_stop(), THINK, p->number);
		checking_the_first_fork_wait(&i, &p->waiting_time_of_the_fork);
		taken_forks(p);
		eating(p, time);
		put_down_forks(p);
		sleeping(p);
	}
	return (NULL);
}

static void		init_thread(t_philo_one *philo_one)
{
	int i;

	i = -1;
	if (philo_one->conf->ntepme > 0)
	{
		philo_one->conf->count_eating = philo_one->conf->ntepme *
										philo_one->conf->numb_phil;
		while (++i < philo_one->conf->numb_phil)
		{
			pthread_create(philo_one->philo[i].thread, NULL, stream2,
												(void *)&philo_one->philo[i]);
			usleep(10);
		}
	}
	else if (philo_one->conf->ntepme == -1)
	{
		philo_one->conf->count_eating = -1;
		while (++i < philo_one->conf->numb_phil)
		{
			pthread_create(philo_one->philo[i].thread, NULL, stream,
												(void *)&philo_one->philo[i]);
			usleep(10);
		}
	}
}

int				main(int argc, char **argv)
{
	t_configuration_simulation	*conf;
	t_philo_one					*philo_one;

	conf = init_struct_conf();
	g_flag = 1;
	pthread_mutex_init(&g_wrt, NULL);
	pthread_mutex_init(&g_wait, NULL);
	if (argv_parser(conf, argc, argv))
	{
		freeing(conf);
		return (EXIT_FAILURE);
	}
	philo_one = init_struct_philo(conf);
	init_thread(philo_one);
	checking_death_and_ntepme(philo_one);
	freeing_memory(philo_one);
	return (EXIT_SUCCESS);
}
