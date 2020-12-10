/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:49 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/10 17:55:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int 		checking_argv_for_digit(char *argvi, size_t *num)
{
	while (*argvi >= '0' && (*argvi)++ <= '9')
		*num = (*num) * 10 + (*num - '0');
	if (*argvi)
		return(EXIT_FAILURE);
	return (0);
}

static int	argv_parser(t_philo_pharam *data, int argc, char **argv)
{

	(void)argv;
	if (argc < 5 || argc > 6)
	{
		write(1, "ERROR: invalid number of arguments. should be 5 of 6.\n", 56);
		return (EXIT_FAILURE);
	}
	if (checking_argv_for_digit(argv[1], &data->numb_phil))
	{
		write(1, "ERROR: number of philosophers must be positive number\n", 56);
		return (EXIT_FAILURE);
	}

	return (0);
}

int		main(int argc, char **argv)
{
	t_philo_pharam data;

	memset(&data, 0, sizeof(data));
	if ((argv_parser(&data, argc, argv)))
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}

