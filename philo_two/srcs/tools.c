/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:09:26 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/29 10:19:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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
