/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:10:02 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/28 20:18:25 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	have_lunch(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->no_eatdie);
	if (gettimeofday(&philo->time_lunch, NULL) == -1)
		return (print_error("Error with timings :(", 0));
	print_info(*philo, EAT_EM, EAT);
	philo->lunches++;
	pthread_mutex_unlock(&philo->args->no_eatdie);
	if (philo->lunches == philo->args->n_lunch)
		philo->args->meals++;
	if (sleep_dude(philo->args->eat, philo))
		return (1);
	return (0);
}

void	eat_plz(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->fork);
		print_info(*philo, FORK_EM, FORK);
		pthread_mutex_lock(&philo->right->fork);
		print_info(*philo, FORK_EM, FORK);
		have_lunch(philo);
		pthread_mutex_unlock(&philo->right->fork);
		pthread_mutex_unlock(&philo->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right->fork);
		print_info(*philo, FORK_EM, FORK);
		pthread_mutex_lock(&philo->fork);
		print_info(*philo, FORK_EM, FORK);
		have_lunch(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->right->fork);
	}
}

void	sleep_plz(t_philo *philo)
{
	print_info(*philo, SLEEP_EM, SLEEP);
	sleep_dude(philo->args->sleep, philo);
}

void	lets_think(t_philo *philo)
{
	print_info(*philo, THINK_EM, THINK);
}

int	check_death(t_philo *philo)
{
	struct timeval	time_now;
	t_philo			*tmp;

	tmp = philo;
	while (tmp->left && tmp->args->meals != philo->args->n_philos)
	{
		pthread_mutex_lock(&tmp->args->no_eatdie);
		if (gettimeofday(&time_now, NULL) == -1)
			return (1);
		if (calculate_ms(tmp->time_lunch, time_now) > tmp->args->die)
		{
			print_info(*tmp, DEATH_EM, DEATH);
			pthread_mutex_unlock(&tmp->fork);
			pthread_mutex_unlock(&tmp->right->fork);
			pthread_mutex_unlock(&tmp->args->no_eatdie);
			break ;
		}
		pthread_mutex_unlock(&tmp->args->no_eatdie);
		tmp = tmp->left;
	}
	return (0);
}
