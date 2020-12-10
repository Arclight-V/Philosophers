/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:58:49 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/10 17:17:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	argv_parser(int argc, char **argv)
{
	int		i;

	(void)argv;
	if (argc < 5 || argc > 6)
	{
		write(1, "ERROR : invalid number of arguments. should be 4.\n", 51);
		return (EXIT_FAILURE);
	}
	i = 0;
	
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo_pharam data;

	memset(&data, 0, sizeof(data));
	if ((argv_parser(argc, argv)))
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}

