/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:21:35 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/28 16:32:16 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*do_smth(void *thread_arg)
{
	t_philo			*philo;

	philo = thread_arg;
	while (philo->args->alive && philo->args->meals != philo->args->n_philos)
	{
		eat_plz(philo);
		sleep_plz(philo);
		lets_think(philo);
	}
	return (NULL);
}

int	create_table(t_philo **philos, t_args	*args)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < args->n_philos)
		if (lst_addback_circle(philos, new_philo(++i, args)))
			return (1);
	philo = *philos;
	i = -1;
	while (++i < args->n_philos)
	{
		if (pthread_create(&philo->thr_id, NULL, do_smth, philo))
			return (print_error("Error creating threads", 0));
		philo = philo->left;
	}
	if (check_death(philo))
		return (1);
	i = -1;
	while (++i < args->n_philos)
	{
		if (pthread_join(philo->thr_id, NULL))
			return (print_error("Error joining threads", 0));
		philo = philo->left;
	}
	return (0);
}
