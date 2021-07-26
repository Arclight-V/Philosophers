/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:43:55 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/02 14:42:21 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_configuration_simulation	*init_struct_conf(void)
{
	t_configuration_simulation *new_struct;

	new_struct = (t_configuration_simulation *)malloc(
											sizeof(t_configuration_simulation));
	new_struct->buf = (char *)malloc(sizeof(char) * 50);
	return (new_struct);
}

static void					init_philo_struct_2(t_philo **philo,
				t_configuration_simulation *conf, t_philo_three *philo_three)
{
	int	i;

	i = -1;
	while (++i < conf->numb_phil)
	{
		(*philo)[i].number = i + 1;
		(*philo)[i].conf = conf;
		(*philo)[i].waiting_time_of_the_fork = 0;
		(*philo)[i].id = &philo_three->all_id[i];
		(*philo)[i].all_id = philo_three->all_id;
		if (conf->ntepme > 0)
			(*philo)[i].loop = conf->ntepme;
		else
			(*philo)[i].loop = EXECUTE_LOOP;
		(*philo)[i].forks = philo_three->forks;
	}
	i = -1;
}

t_philo_three				*init_struct_philo(t_configuration_simulation *conf)
{
	t_philo_three	*new_struct;

	new_struct = (t_philo_three *)malloc(sizeof(t_philo_three));
	new_struct->conf = conf;
	new_struct->philo = (t_philo *)malloc(sizeof(t_philo) * conf->numb_phil);
	sem_unlink("/forks");
	new_struct->forks = sem_open("/forks", O_CREAT, 0666, conf->numb_phil);
	new_struct->all_id = (pid_t *)malloc(sizeof(pid_t) * conf->numb_phil);
	init_philo_struct_2(&new_struct->philo, conf, new_struct);
	new_struct->conf->start = get_ms();
	return (new_struct);
}
