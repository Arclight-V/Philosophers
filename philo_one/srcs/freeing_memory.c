/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 13:42:07 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:25:06 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		freeing(t_configuration_simulation *conf)
{
	free(conf->buf);
	free(conf);
	pthread_mutex_destroy(&g_wait);
	pthread_mutex_destroy(&g_wrt);
}

void		freeing_memory(t_philo_one *philo_one)
{
	int		i;

	free(philo_one->conf->buf);
	i = -1;
	while (++i < philo_one->conf->numb_phil)
		pthread_mutex_destroy(&philo_one->all_fork[i]);
	pthread_mutex_destroy(&g_wait);
	pthread_mutex_destroy(&g_wrt);
	free(philo_one->all_fork);
	free(philo_one->all_thread);
	free(philo_one->conf);
	free(philo_one->philo);
	free(philo_one);
}
