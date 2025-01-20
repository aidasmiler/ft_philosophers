/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:47:50 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/28 20:20:04 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *str, int printUsage)
{
	printf("%s\n", str);
	if (printUsage)
		printf("Usage: ./philo n_philos die eat sleep [n_lunches]\n");
	return (1);
}

void	print_philo(t_philo philo)
{
	printf("Philo: %d. Left: %p, Right: %p\n", philo.id, philo.left,
		philo.right);
	printf("Philo args: %p\n", philo.args);
	printf("Args: n_philos: %d, die: %lu, eat: %u, sleep: %u, n_lunch: %d\n",
		philo.args->n_philos, philo.args->die, \
			philo.args->eat, philo.args->sleep, philo.args->n_lunch);
}

void	print_info(t_philo philo, char *emoji, char *sentence)
{
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	pthread_mutex_lock(&philo.args->print);
	if (philo.args->alive)
	{
		if (sentence == DEATH)
			philo.args->alive = false;
		printf("%s %lu: Philosopher %d %s\n", emoji,
			calculate_ms(philo.args->time_zero, time_now), philo.id, sentence);
		printf("%s", NOCOL);
	}
	pthread_mutex_unlock(&philo.args->print);
}
