/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:49 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/15 11:56:28 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		checking_argv_for_digit(char *argvi, long long *num, int i)
{
	long long result;

	result = 0;
	while (*argvi >= '0' && *argvi <= '9')
	{
		result = result * 10 + (*argvi - '0');
		argvi++;
	}
	*num = result;
	if (*argvi)
		return(ARGUMENT_IS_NOT_NUMBER);
	if (i == 1 && *num > 200)
		return (MORE_THAN_200_PHILOSPHERS);
	if (i == 2 && *num < 60)
		return (TIME_TO_DIE_UNDER_60);
	if (i == 3 && *num < 60)
		return (TIME_TO_EAT_UNDER_60);
	if (i == 4 && *num < 60)
		return (TIME_TO_SLEEP_UNDER_60);
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
	int		error_number;

	if (argc < 5 || argc > 6)
		return (print_error(INVALID_NUMBER_ARGUMENTS));
	i = 0;
	while (++i < argc)
	{
		if ((error_number = checking_argv_for_digit(argv[i], return_pharam(data, i), i)))
			return (print_error(error_number));
	}

	return (0);
}

void		*eat(void *data)
{
	t_philo_pharam *tmp = (t_philo_pharam *) data;
	// int i = tmp->time_eat;
	(void)tmp;
	write(1, "is eating\n", 10);
	return (data);
}

int			main(int argc, char **argv)
{
	t_philo_pharam data;

	memset(&data, -1, sizeof(t_philo_pharam));
	if ((argv_parser(&data, argc, argv)))
		return (EXIT_FAILURE);
	if (data.time_eat == 0)
		return (0);
	int status;
	int	status2;
	pthread_t threads[data.numb_phil];
	for (int i = 0; i < data.numb_phil; i++)
		status = pthread_create(&threads[i], NULL, eat, (void*) &data);
	for (int i = 0; i < data.numb_phil; i++)
		status = pthread_join(threads[i], (void**)&status2);

	return (EXIT_SUCCESS);
}

