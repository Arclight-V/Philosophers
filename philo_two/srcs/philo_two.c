/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:49 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:36:55 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			*stream2(void *data)
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

void			*stream(void *data)
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

static void		init_thread(t_philo_two *philo_two)
{
	int i;

	i = -1;
	if (philo_two->conf->ntepme > 0)
	{
		philo_two->conf->count_eating = philo_two->conf->ntepme *
										philo_two->conf->numb_phil;
		while (++i < philo_two->conf->numb_phil)
		{
			pthread_create(philo_two->philo[i].thread, NULL, stream2,
												(void *)&philo_two->philo[i]);
			usleep(10);
		}
	}
	else if (philo_two->conf->ntepme == -1)
	{
		philo_two->conf->count_eating = -1;
		while (++i < philo_two->conf->numb_phil)
		{
			pthread_create(philo_two->philo[i].thread, NULL, stream,
												(void *)&philo_two->philo[i]);
			usleep(10);
		}
	}
}

int				main(int argc, char **argv)
{
	t_configuration_simulation	*conf;
	t_philo_two					*philo_two;

	conf = init_struct_conf();
	sem_unlink("/g_wrt");
	g_wrt = sem_open("/g_wrt", O_CREAT, 0666, 1);
	sem_unlink("/g_wait");
	g_wait = sem_open("/g_wait", O_CREAT, 0666, 1);
	sem_unlink("/g_wait_fork");
	g_wait_fork = sem_open("/g_wait_fork", O_CREAT, 0666, 1);
	g_flag = 1;
	if (argv_parser(conf, argc, argv))
	{
		freeing(conf);
		return (EXIT_FAILURE);
	}
	philo_two = init_struct_philo(conf);
	init_thread(philo_two);
	checking_death_and_ntepme(philo_two);
	freeing_memory(philo_two);
	return (EXIT_SUCCESS);
}
