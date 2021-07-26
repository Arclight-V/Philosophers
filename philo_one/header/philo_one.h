/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:20:58 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:40:58 by anatashi         ###   ########.fr       */
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
# define ERROR_2 "ERROR: number must be positive number.\n"
# define ERROR_3 "ERROR: do not test with more than 200 philosphers.\n"
# define ERROR_4 "ERROR: do not test with time_to_die under 60 ms.\n"
# define ERROR_5 "ERROR: do not test with time_to_eat under 60 ms.\n"
# define ERROR_6 "ERROR: Do not test with time_to_sleep under 60 ms.\n"
# define ERROR_7 "ERROR: number of philosophers and also the number of forks\n"
# define TAKEN_FORK " has taken a fork\n"
# define EATING " is eating\n"
# define SLEEP " is sleeping\n"
# define THINK " is thinking\n"
# define DEAD " died\n"

struct timeval					tv1;
struct timeval					tv2;
struct timeval					dtv;
pthread_mutex_t					g_wrt;
pthread_mutex_t					g_wait;
int								g_flag;

/*
** numb_phil  	- number_of_philosopher
** time_die   	- time to die
** time_eat		- time to eat
** time_sleep	- time to sleep
** ntepme	  	- [number_of_times_each_philosopher_must_eat]
** start		- the start time of the simulation
** bud[50]		- buffer for message output
*/
typedef	struct					s_configuration_simulation
{
	long						numb_phil;
	long						time_die;
	long						time_eat;
	long						time_sleep;
	long						ntepme;
	long						count_eating;
	long						start;
	char						*buf;
}								t_configuration_simulation;

/*
** *fork					- the forks state with amutex for each of them
** *thread					- each philosopher should be a thread
**	number					- current thread
**  loop					- the interrupt g_flag cycle
*/
typedef struct					s_philo
{
	pthread_t					*thread;
	t_configuration_simulation	*conf;
	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;
	long						waiting_time_of_the_fork;
	int							loop;
	unsigned int				number;
}								t_philo;

typedef struct					s_philo_one
{
	t_configuration_simulation	*conf;
	t_philo						*philo;
	pthread_mutex_t				*all_fork;
	pthread_t					*all_thread;
}								t_philo_one;

enum
{
	INVALID_NUMBER_ARGUMENTS,
	ARGUMENT_IS_NOT_NUMBER,
	MORE_THAN_200_PHILOSPHERS,
	LESS_THAN_2_PHILOSPHERS,
	TIME_TO_DIE_UNDER_60,
	TIME_TO_EAT_UNDER_60,
	TIME_TO_SLEEP_UNDER_60,
	ONE_PHILO,
	EXECUTE_LOOP,
	STOP_LOOP = 0,
};

/*
** the following functions do not control the return value:
** void *malloc(size_t size);
** int gettimeofday(struct timeval *tv, struct timezone *tz);
** int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
**                          void *(*start_routine) (void *), void *arg);
** int pthread_join(pthread_t thread, void **retval);
** int pthread_detach(pthread_t thread);
** int usleep(useconds_t usec);
** int pthread_mutex_init(pthread_mutex_t *__mutex,
**								const pthread_mutexattr_t *__mutexattr);
** int pthread_mutex_unlock(pthread_mutex_t *__mutex);
** int pthread_mutex_lock(pthread_mutex_t *__mutex);
** int pthread_mutex_destroy(pthread_mutex_t *__mutex);
*/

int								main(int argc, char **argv);
int								print_error(int error_number);
int								argv_parser(t_configuration_simulation *conf,
										int argc, char **argv);
t_configuration_simulation		*init_struct_conf();
t_philo_one						*init_struct_philo(t_configuration_simulation
												*conf);
void							ft_putstr_fd(char *str, int fd);

/*
** return len of a string. Input is != NULL
*/
size_t							ft_strlen(char *str);

/*
** return the current timestamp in miliseconds
*/
long							get_ms();

/*
** return the current timestamp from the beginning
** of the simulation in miliseconds
*/
long							time_stop();

/*
** checks whether the philosopher is dead and
** if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’
** the simulation will stop.
*/
void							checking_death_and_ntepme(t_philo_one
															*philo_one);
void							print_message(char **buf, long long ms,
											char *str, int count);
void							checking_the_first_fork_wait(int *i,
											long *waiting_time_of_the_fork);
void							taken_forks(t_philo *p);
void							eating(t_philo *p, long time);
void							sleeping(t_philo *p);
void							put_down_forks(t_philo *p);
void							freeing_memory(t_philo_one *philo_three);
void							freeing(t_configuration_simulation *conf);
#endif
