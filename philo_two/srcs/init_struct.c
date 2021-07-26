/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:43:55 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/26 21:33:05 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_configuration_simulation	*init_struct_conf(void)
{
	t_configuration_simulation *new_struct;

	new_struct = (t_configuration_simulation *)malloc(
											sizeof(t_configuration_simulation));
	new_struct->buf = (char *)malloc(sizeof(char) * 50);
	return (new_struct);
}

static void					init_philo_struct_2(t_philo **philo,
					t_configuration_simulation *conf, t_philo_two *philo_two)
{
	int	i;

	i = -1;
	while (++i < conf->numb_phil)
	{
		(*philo)[i].number = i + 1;
		(*philo)[i].thread = &philo_two->all_thread[i];
		(*philo)[i].conf = conf;
		(*philo)[i].waiting_time_of_the_fork = 0;
		(*philo)[i].loop = EXECUTE_LOOP;
		(*philo)[i].forks = philo_two->forks;
	}
	i = -1;
}

t_philo_two					*init_struct_philo(t_configuration_simulation *conf)
{
	t_philo_two *new_struct;

	new_struct = (t_philo_two *)malloc(sizeof(t_philo_two));
	new_struct->conf = conf;
	new_struct->philo = (t_philo *)malloc(sizeof(t_philo) * conf->numb_phil);
	new_struct->all_thread = (pthread_t *)malloc(sizeof(pthread_t) *
															conf->numb_phil);
	sem_unlink("/forks");
	new_struct->forks = sem_open("/forks", O_CREAT, 0666, conf->numb_phil);
	init_philo_struct_2(&new_struct->philo, conf, new_struct);
	new_struct->conf->start = get_ms();
	return (new_struct);
}
