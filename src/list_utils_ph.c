/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_ph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:55:37 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/28 00:58:29 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(int id, t_args *args)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
	{
		print_error("Error creating a new philosopher", 0);
		return (NULL);
	}
	new_philo->id = id;
	new_philo->time_lunch.tv_sec = args->time_zero.tv_sec;
	new_philo->time_lunch.tv_usec = args->time_zero.tv_usec;
	new_philo->args = args;
	new_philo->left = NULL;
	new_philo->right = NULL;
	new_philo->lunches = 0;
	if (pthread_mutex_init(&new_philo->fork, NULL))
	{
		print_error("Failed to create the fork of this philo", 0);
		return (NULL);
	}
	return (new_philo);
}

int	lst_addback_circle(t_philo **philos, t_philo *new_philo)
{
	if (!new_philo)
		return (1);
	if (!*philos)
	{
		*philos = new_philo;
		(*philos)->left = *philos;
		(*philos)->right = *philos;
	}
	else
	{
		new_philo->left = *philos;
		new_philo->right = (*philos)->right;
		(*philos)->right->left = new_philo;
		(*philos)->right = new_philo;
	}
	return (0);
}
