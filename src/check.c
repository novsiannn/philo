/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:37:45 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/24 11:10:49 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	put_down_forks(t_philo *philos)
{
	pthread_mutex_unlock(philos->forkl);
	pthread_mutex_unlock(philos->forkr);
	return (1);
}

int	one_philo(t_philo *philos)
{
	if (philos->params->num_p == 1)
	{
		pthread_mutex_lock(philos->forkl);
		printf("%lld Philosopher %i has taken a fork\n", \
		time_now() - philos->start, philos->id);
		usleep(philos->params->ttd);
		put_down_forks(philos);
		return (1);
	}
	return (0);
}

int	arg_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && (ft_is_digit(arg[i]) || arg[0] == '+'))
	{
		if (arg[i] == '+')
		{
			i++;
			if (!ft_is_digit(arg[i]))
				return (0);
		}
		i++;
	}
	if (arg[i] != '\0' && !ft_is_digit(arg[i]))
		return (0);
	return (1);
}

int	ft_is_digit(char n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}
