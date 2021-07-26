/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:37:40 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:44:51 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static long	checking_argv_for_digit(char *argvi, long *num, int i)
{
	long result;

	result = 0;
	while (*argvi >= '0' && *argvi <= '9')
	{
		result = result * 10 + (*argvi - '0');
		argvi++;
	}
	*num = result;
	if (*argvi)
		return (ARGUMENT_IS_NOT_NUMBER);
	if (i == 1 && *num > 200)
		return (MORE_THAN_200_PHILOSPHERS);
	if (i == 1 && (*num == 1 || *num == 0))
		return (ONE_PHILO);
	if (i == 2 && *num < 60)
		return (TIME_TO_DIE_UNDER_60);
	if (i == 3 && *num < 60)
		return (TIME_TO_EAT_UNDER_60);
	if (i == 4 && *num < 60)
		return (TIME_TO_SLEEP_UNDER_60);
	return (0);
}

static long	*return_pharam(t_configuration_simulation *data, int i)
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

int			argv_parser(t_configuration_simulation *conf, int argc,
								char **argv)
{
	int	i;
	int	err;

	if (argc < 5 || argc > 6)
		return (print_error(INVALID_NUMBER_ARGUMENTS));
	if (argc == 5)
		conf->ntepme = -1;
	i = 0;
	while (++i < argc)
	{
		if ((err = checking_argv_for_digit(argv[i], return_pharam(conf, i), i)))
			return (print_error(err));
	}
	return (0);
}
