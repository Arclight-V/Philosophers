/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 12:32:30 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:41:47 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		freeing(t_configuration_simulation *conf)
{
	free(conf->buf);
	free(conf);
	sem_close(g_wrt);
	sem_close(g_wait);
	sem_close(g_wait_fork);
	sem_unlink("/g_wrt");
	sem_unlink("/g_wait");
	sem_unlink("/g_wait_fork");
}

void		freeing_memory(t_philo_three *philo_three)
{
	free(philo_three->conf->buf);
	sem_close(philo_three->forks);
	sem_close(g_wrt);
	sem_close(g_wait);
	sem_close(g_wait_fork);
	sem_unlink("/forks");
	sem_unlink("/g_wrt");
	sem_unlink("/g_wait");
	sem_unlink("/g_wait_fork");
	free(philo_three->conf);
	free(philo_three->philo);
	free(philo_three->all_id);
	free(philo_three);
}
