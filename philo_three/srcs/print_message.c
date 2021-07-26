/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:46:43 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/26 21:58:06 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** writes a number to a string and increments the index of that string.
** After writing a number, the index is equal to the location of
** the last written character in the string
*/

static void		ft_putnbr_str(long num, char **buf, int *i)
{
	if (num >= 10)
		ft_putnbr_str(num / 10, buf, i);
	(*buf)[*i] = (char)(num % 10 + '0');
	(*i)++;
}

void			print_message(char **buf, long long ms, char *str, int count)
{
	int		i;
	int		j;

	if (g_flag == 1)
	{
		sem_wait(g_wrt);
		i = 0;
		j = -1;
		ft_putnbr_str(ms, buf, &i);
		(*buf)[i++] = ' ';
		ft_putnbr_str(count, buf, &i);
		while (str[++j])
		{
			(*buf)[i] = str[j];
			i++;
		}
		(*buf)[i] = '\0';
		write(1, *buf, i);
		sem_post(g_wrt);
	}
}
