/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:21:44 by anatashi          #+#    #+#             */
/*   Updated: 2021/01/08 15:44:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

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
sem_t							*g_wrt;
sem_t							*g_wait;
sem_t							*g_wait_fork;
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
	long						start;
	char						*buf;
}								t_configuration_simulation;

/*
**  sem						- pointer to the forks from s_pholo_two;
** 	number					- current thread
**  loop					- the interrupt g_flag cycle
*/
typedef struct					s_philo
{
	pid_t						*id;
	pid_t						*all_id;
	t_configuration_simulation	*conf;
	long						waiting_time_of_the_fork;
	sem_t						*forks;
	int							loop;
	unsigned int				number;
}								t_philo;

typedef struct					s_philo_three
{
	t_configuration_simulation	*conf;
	t_philo						*philo;
	sem_t						*forks;
	pid_t						*all_id;

}								t_philo_three;

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
** sem_t *sem_open(const char *name, int oflag,
**						mode_t mode, unsigned int value);
** int sem_unlink(const char *name);
** int sem_post(sem_t *sem);
** int sem_wait(sem_t *sem);
*/
int								main(int argc, char **argv);
int								print_error(int error_number);
int								argv_parser(t_configuration_simulation *conf,
										int argc, char **argv);
t_configuration_simulation		*init_struct_conf();
t_philo_three					*init_struct_philo(t_configuration_simulation
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
void							print_message(char **buf, long long ms,
											char *str, int count);
void							freeing_memory(t_philo_three *philo_three);
void							checking_the_first_fork_wait(int *i,
												long *waiting_time_of_the_fork);
void							taken_forks(t_philo *p);
void							eating(t_philo *p, long time);
void							sleeping(t_philo *p);
void							put_down_forks(t_philo *p);
void							waiting_for_the_process_to_complete_or_die(
													t_philo_three *philo_three,
											t_configuration_simulation *conf);
void							freeing_memory(t_philo_three *philo_two);
void							freeing(t_configuration_simulation *conf);
#endif
