/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:39:57 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:37:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	print_error(int error_number)
{
	if (error_number == INVALID_NUMBER_ARGUMENTS)
		ft_putstr_fd(ERROR_1, 1);
	else if (error_number == ARGUMENT_IS_NOT_NUMBER)
		ft_putstr_fd(ERROR_2, 1);
	else if (error_number == MORE_THAN_200_PHILOSPHERS)
		ft_putstr_fd(ERROR_3, 1);
	else if (error_number == TIME_TO_DIE_UNDER_60)
		ft_putstr_fd(ERROR_4, 1);
	else if (error_number == TIME_TO_EAT_UNDER_60)
		ft_putstr_fd(ERROR_5, 1);
	else if (error_number == TIME_TO_SLEEP_UNDER_60)
		ft_putstr_fd(ERROR_6, 1);
	else if (error_number == ONE_PHILO)
		ft_putstr_fd(ERROR_7, 1);
	return (EXIT_FAILURE);
}
