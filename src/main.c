/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:08:38 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/23 17:38:02 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_args	args_philo;

	philos = NULL;
	if (argc != 5 && argc != 6)
		return (print_error("Wrong Arguments!", 1));
	if (storage_args(argv, argc, &args_philo))
		return (1);
	if (gettimeofday(&args_philo.time_zero, NULL) == -1)
		return (print_error("Error with timings :(", 0));
	if (create_table(&philos, &args_philo))
		return (1);
	return (0);
}
