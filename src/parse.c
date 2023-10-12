/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:29:15 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/12 19:06:57 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_data	*parse_data(char **av)
{
	t_data *params;

	params = malloc(sizeof(t_data));
	if (params == NULL)
		return (NULL);
	params->print = malloc(sizeof(pthread_mutex_t));
	if (params->print == NULL)
		return (NULL);
	params->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if (params->fork == NULL)
		return (NULL);
	params->ttd = ft_atoi(av[2]);
	params->tte = ft_atoi(av[3]);
	params->check_tme = 0;
	params->tts = ft_atoi(av[4]);
	params->eated = 0;
	if (av[5])
	{
		params->check_tme = 1;
		params->tme = ft_atoi(av[5]);
	}
	params->num_p = ft_atoi(av[1]);
	params->ready = 0;
	params->over = 0;
	return (params);
} 

void	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		philos[i].start = 0;
		philos[i].id = i + 1;
		philos[i].meal = 0;
		philos[i].thread = 0;
		philos[i].forkl = &data->fork[i];
		if (philos[i].id == data->num_p)
			philos[i].forkr = &data->fork[0];
		else
			philos[i].forkr = &data->fork[i + 1];
		philos[i].params = data;
		philos[i].iter = 0;
		i++;
	}
}

int	check_death(t_philo *philos)
{
	long int	now;

	pthread_mutex_lock(philos->params->print);
	now = time_now() - philos->meal;
	if (now >= philos->params->ttd)
	{
		pthread_mutex_unlock(philos->params->print);
		ft_print(philos, 5);
		pthread_mutex_unlock(philos->forkl);
		pthread_mutex_unlock(philos->forkr);
		return (1);
	}
	pthread_mutex_unlock(philos->params->print);
	return (0);
}
