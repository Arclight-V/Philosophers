/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 13:46:25 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/28 20:18:54 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_configuration_simulation	*init_struct_conf(void)
{
	t_configuration_simulation *new_struct;

	new_struct = (t_configuration_simulation *)malloc(
										sizeof(t_configuration_simulation));
	new_struct->buf = (char *)malloc(sizeof(char) * 50);
	return (new_struct);
}

static void					init_philo_struct_2(t_philo **philo,
					t_configuration_simulation *conf, t_philo_one *philo_one)
{
	int	i;

	i = -1;
	while (++i < conf->numb_phil)
	{
		(*philo)[i].number = i + 1;
		(*philo)[i].left_fork = &philo_one->all_fork[i];
		pthread_mutex_init((*philo)[i].left_fork, NULL);
		(*philo)[i].right_fork =
							&philo_one->all_fork[(i + 1) % conf->numb_phil];
		(*philo)[i].thread = &philo_one->all_thread[i];
		(*philo)[i].conf = conf;
		(*philo)[i].waiting_time_of_the_fork = 0;
		(*philo)[i].loop = EXECUTE_LOOP;
	}
}

t_philo_one					*init_struct_philo(t_configuration_simulation *conf)
{
	t_philo_one *new_struct;

	new_struct = (t_philo_one *)malloc(sizeof(t_philo_one));
	new_struct->conf = conf;
	new_struct->philo = (t_philo *)malloc(sizeof(t_philo) * conf->numb_phil);
	new_struct->all_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) *
														conf->numb_phil);
	new_struct->all_thread = (pthread_t *)malloc(sizeof(pthread_t) *
														conf->numb_phil);
	init_philo_struct_2(&new_struct->philo, conf, new_struct);
	new_struct->conf->start = get_ms();
	return (new_struct);
}
