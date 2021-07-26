# Philosophers

A project with 3 approaches of solving the Dining Philosophers Problem

## Usage example:
`./philo_one 4 800 200 200 6`

Use `make` or `make re` to compile the project in each folder. There are 4 mandatory and 1 optional options available to the executable file:
### Options:
*  number_of_philosophers 
*  time_to_die
*  time_to_eat
*  time_to_sleep
*  number_of_times_each_philosopher_must_eat (optional)

The program shows the current timestamp in milliseconds of current activity. The simulation stops if the philosopher dies or if specified, when each philosopher has eaten the number of times specified in the option. 


**As mentioned above, there are 3 approaches of solving the Dining Philosophers Problem:**
1. `./philo_one` - Using mutex for each fork, each philosopher is a thread (One fork between each philosopher, therefore there is a fork at the right and at the left of each philosopher - it's a part of the subject).
2. `./philo_two` - Using semaphores to represent the forks, each philosooher is a thread (All the forks are in the middle of the table - it's a part of the subject).
3. `./philo_three` - Using semaphores to represent the forks, each philosooher is a process (All the forks are in the middle of the table - it's a part of the subject).

Enjoy! 😉
