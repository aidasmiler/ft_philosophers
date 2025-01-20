/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:13:33 by airodrig          #+#    #+#             */
/*   Updated: 2022/03/23 20:46:30 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi_philo(const char *str)
{
	long long			nb;
	int					cnt;

	nb = 0;
	cnt = 0;
	if (str[cnt] == '-')
		return (-1);
	else if (str[cnt] == '+')
		cnt++;
	while (str[cnt] && str[cnt] >= '0' && str[cnt] <= '9')
		nb = nb * 10 + str[cnt++] - '0';
	if ((str[cnt] && !ft_isdigit(str[cnt])) || nb > 2147483647
		|| nb < -2147483648)
		return (-1);
	return (nb);
}

unsigned long	calculate_ms(struct timeval time_base, struct timeval time_now)
{
	return (time_now.tv_sec * 1000 + time_now.tv_usec / 1000
		- time_base.tv_sec * 1000 - time_base.tv_usec / 1000);
}

int	sleep_dude(int ms, t_philo *philo)
{
	struct timeval	time_base;
	struct timeval	time_now;

	if (gettimeofday(&time_base, NULL) == -1)
		return (print_error("Error with timings", 0));
	while (gettimeofday(&time_now, NULL) != -1 && philo->args->alive
		&& (((time_now.tv_sec * 1000 + time_now.tv_usec / 1000)
				- (time_base.tv_sec * 1000 + time_base.tv_usec / 1000)) < ms))
		usleep(50);
	return (0);
}
