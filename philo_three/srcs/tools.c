/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:09:26 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/05 09:02:58 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

long	time_stop(void)
{
	gettimeofday(&tv2, NULL);
	dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
	dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
	return (dtv.tv_sec * 1000 + dtv.tv_usec / 1000);
}

long	get_ms(void)
{
	gettimeofday(&tv1, NULL);
	return (tv1.tv_sec * 1000 + tv1.tv_usec / 1000);
}

size_t	ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	waiting_for_the_process_to_complete_or_die(t_philo_three *philo_three,
								t_configuration_simulation *conf)
{
	int i;

	waitpid(-1, &i, 0);
	i = -1;
	while (++i < conf->ntepme)
		waitpid(philo_three->all_id[i], NULL, 0);
	i = -1;
	while (++i < conf->ntepme)
		kill(philo_three->all_id[i], 0);
}
