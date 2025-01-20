/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:22:43 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/28 20:21:02 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define FORK_EM "\033[0;32m🍴"
# define EAT_EM "\033[0;33m🍽️ "
# define SLEEP_EM "\033[0;34m💤"
# define THINK_EM "\033[0;37m🤔"
# define DEATH_EM "\033[0;31m💀"
# define NOCOL "\033[0m"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "died"

typedef struct s_args
{
	int				n_philos;
	unsigned long	die;
	int				eat;
	int				sleep;
	int				n_lunch;
	pthread_mutex_t	print;
	pthread_mutex_t	no_eatdie;
	struct timeval	time_zero;
	bool			alive;
	int				meals;
}t_args;

typedef struct s_philo
{
	pthread_t		thr_id;
	int				id;
	t_args			*args;
	struct s_philo	*left;
	struct s_philo	*right;
	pthread_mutex_t	fork;
	struct timeval	time_lunch;
	int				lunches;
}t_philo;

//////////////////////////////////////////////
// parser.c
//////////////////////////////////////////////

int				storage_args(char **argv, int argc, t_args *args);

//////////////////////////////////////////////
// utils_philo.c
//////////////////////////////////////////////

int				ft_atoi_philo(const char *str);
unsigned long	calculate_ms(struct timeval time_base, struct timeval time_now);
int				sleep_dude(int ms, t_philo *philo);

//////////////////////////////////////////////
// info_philo.c
//////////////////////////////////////////////

int				print_error(char *str, int printUsage);
void			print_philo(t_philo philo);
void			print_info(t_philo philo, char *emoji, char *sentence);

//////////////////////////////////////////////
// eat_sleep_think.c
//////////////////////////////////////////////

void			eat_plz(t_philo *philo);
void			sleep_plz(t_philo *philo);
void			lets_think(t_philo *philo);
int				check_death(t_philo *philo);

//////////////////////////////////////////////
// create_philos.c
//////////////////////////////////////////////

int				create_table(t_philo **philo, t_args	*args);

//////////////////////////////////////////////
// list_utils_ph.c
//////////////////////////////////////////////

t_philo			*new_philo(int id, t_args *args);
int				lst_addback_circle(t_philo **philos, t_philo *new_philo);

#endif
