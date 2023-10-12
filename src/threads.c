/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:43 by novsiann          #+#    #+#             */
/*   Updated: 2023/10/10 21:38:59 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_mutex(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		pthread_mutex_init(philos[i].forkl, NULL);
		i++;
	}
	pthread_mutex_init(data->print, NULL);
}

void	create_threads(t_philo *philos)
{
	int			i;
	long int	k;
	
	i = 0;
	while (i < philos->params->num_p)
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
	i = 0;
	k = time_now();
	while (i < philos->params->num_p)
	{
		philos[i].start = k;
		philos[i].meal = k;
		i++;
	}
	philos->params->ready = 1;
}
