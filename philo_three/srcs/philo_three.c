/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:49 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:47:52 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void		*check_died(void *data)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)data;
	while (1)
	{
		sem_wait(g_wait);
		if (time_stop() - p->waiting_time_of_the_fork
			> p->conf->time_die)
		{
			sem_post(g_wait);
			print_message(&p->conf->buf, time_stop(), DEAD, p->number);
			g_flag = 0;
			i = -1;
			while (++i < p->conf->numb_phil)
				kill(p->all_id[i], SIGKILL);
			exit(EXIT_FAILURE);
		}
		sem_post(g_wait);
		if (p->loop == STOP_LOOP)
			exit(EXIT_FAILURE);
	}
}

void			stream2(t_philo *p)
{
	pthread_t	*died;
	int			i;
	long		time;

	i = 0;
	time = 0;
	died = (pthread_t *)malloc(sizeof(pthread_t));
	p->loop = p->conf->ntepme;
	pthread_create(died, NULL, check_died, (void *)p);
	while (p->loop != STOP_LOOP)
	{
		print_message(&p->conf->buf, time_stop(), THINK, p->number);
		checking_the_first_fork_wait(&i, &p->waiting_time_of_the_fork);
		taken_forks(p);
		eating(p, time);
		put_down_forks(p);
		--p->loop;
		if (p->loop == STOP_LOOP)
			break ;
		sleeping(p);
	}
	exit(EXIT_FAILURE);
}

void			stream(t_philo *p)
{
	pthread_t	*died;
	int			i;
	long		time;

	i = 0;
	time = 0;
	died = (pthread_t *)malloc(sizeof(pthread_t));
	pthread_create(died, NULL, check_died, (void *)p);
	while (p->loop == EXECUTE_LOOP)
	{
		print_message(&p->conf->buf, time_stop(), THINK, p->number);
		checking_the_first_fork_wait(&i, &p->waiting_time_of_the_fork);
		taken_forks(p);
		eating(p, time);
		put_down_forks(p);
		sleeping(p);
	}
	exit(EXIT_FAILURE);
}

static	void	init_thread(t_philo_three *philo_three)
{
	int i;

	i = -1;
	if (philo_three->conf->ntepme > 0)
	{
		while (++i < philo_three->conf->numb_phil)
		{
			if (!(*philo_three->philo[i].id = fork()))
				stream2(&philo_three->philo[i]);
			usleep(10);
		}
	}
	else if (philo_three->conf->ntepme == -1)
	{
		while (++i < philo_three->conf->numb_phil)
		{
			if (!(*philo_three->philo[i].id = fork()))
				stream(&philo_three->philo[i]);
			usleep(10);
		}
	}
}

int				main(int argc, char **argv)
{
	t_configuration_simulation	*conf;
	t_philo_three				*philo_three;

	conf = init_struct_conf();
	g_flag = 1;
	sem_unlink("/g_wrt");
	g_wrt = sem_open("/g_wrt", O_CREAT, 0666, 1);
	sem_unlink("/g_wait");
	g_wait = sem_open("/g_wait", O_CREAT, 0666, 1);
	sem_unlink("/g_wait_fork");
	g_wait_fork = sem_open("/g_wait_fork", O_CREAT, 0666, 1);
	if (argv_parser(conf, argc, argv))
	{
		freeing(conf);
		return (EXIT_FAILURE);
	}
	philo_three = init_struct_philo(conf);
	init_thread(philo_three);
	waiting_for_the_process_to_complete_or_die(philo_three, conf);
	freeing_memory(philo_three);
	return (EXIT_SUCCESS);
}
