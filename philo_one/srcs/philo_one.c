/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:49 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/10 20:23:22 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int 		checking_argv_for_digit(char *argvi, long long *num)
{
	int		result;

	result = 0;
	while (*argvi >= '0' && *argvi <= '9')
	{
		*num = result * 10 + (*argvi - '0');
		argvi++;
	}
	if (*argvi)
		return(EXIT_FAILURE);
	return (0);
}

long long	*return_pharam(t_philo_pharam *data, int i)
{
	if (i == 1)
		return (&data->numb_phil);
	else if (i == 2)
		return (&data->time_die);
	else if (i == 3)
		return (&data->time_eat);
	else if (i == 4)
		return (&data->time_sleep);
	else if (i == 5)
		return (&data->ntepme);
	return (0);
}

static int	argv_parser(t_philo_pharam *data, int argc, char **argv)
{

	int 	i;

	if (argc < 5 || argc > 6)
	{
		write(1, ERROR_1, 56);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (++i < argc)
	{
		if (checking_argv_for_digit(argv[i], return_pharam(data, i)))
		{
			write(1, ERROR_2, 56);
			return (EXIT_FAILURE);
		}
	}

	return (0);
}

int			main(int argc, char **argv)
{
	t_philo_pharam data;

	memset(&data, -1, sizeof(t_philo_pharam));
	if ((argv_parser(&data, argc, argv)))
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}

