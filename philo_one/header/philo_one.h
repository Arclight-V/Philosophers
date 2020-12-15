/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:20:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/15 11:56:25 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR_1 "ERROR: invalid number of arguments. should be 5 of 6.\n"
# define ERROR_2 "ERROR: number of philosophers must be positive number.\n"
# define ERROR_3 "ERROR: do not test with more than 200 philosphers.\n"
# define ERROR_4 "ERROR: do not test with time_to_die under 60 ms.\n"
# define ERROR_5 "ERROR: do not test with time_to_eat under 60 ms.\n"
# define ERROR_6 "ERROR: Do not test with time_to_sleep under 60 ms.\n"

/*
** numb_phil  - number_of_philosopher ()
** time_die   - time to die
** time_eat   - time to eat
** time_sleep - time to sleep
** ntepme	  - [number_of_times_each_philosopher_must_eat]
*/

enum
{
	INVALID_NUMBER_ARGUMENTS,
	ARGUMENT_IS_NOT_NUMBER,
	MORE_THAN_200_PHILOSPHERS,
	TIME_TO_DIE_UNDER_60,
	TIME_TO_EAT_UNDER_60,
	TIME_TO_SLEEP_UNDER_60,

};

typedef	struct	s_philo_pharam
{
	long long	numb_phil;
	long long	time_die;
	long long	time_eat;
	long long	time_sleep;
	long long	ntepme;
}				t_philo_pharam;

int		main(int argc, char **argv);
int		tmp(void);
int		print_error(int error_number);
void 	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(char *str);

#endif
