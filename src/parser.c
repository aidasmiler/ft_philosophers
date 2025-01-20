/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:32:02 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/23 20:24:40 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	storage_args(char **argv, int argc, t_args *args)
{
	int	i;
	int	tmp_die;

	i = 0;
	while (++i < argc)
		if (!argv[i] || !argv[i][0])
			return (print_error("Wrong arguments", 0));
	args->n_philos = ft_atoi_philo(argv[1]);
	tmp_die = ft_atoi_philo(argv[2]);
	args->eat = ft_atoi_philo(argv[3]);
	args->sleep = ft_atoi_philo(argv[4]);
	args->alive = true;
	args->meals = 0;
	if (argc == 6)
		args->n_lunch = ft_atoi_philo(argv[5]);
	else
		args->n_lunch = 0;
	if (args->n_philos == -1 || tmp_die == -1 || args->eat == -1
		|| args->sleep == -1 || args->n_lunch == -1)
		return (print_error("Wrong args", 0));
	args->die = tmp_die;
	if (pthread_mutex_init(&args->print, NULL)
		|| pthread_mutex_init(&args->no_eatdie, NULL))
		return (print_error("Failed to create mutex", 0));
	return (0);
}
