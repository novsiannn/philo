/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:39:43 by novsiann          #+#    #+#             */
/*   Updated: 2023/10/10 14:40:10 by novsiann         ###   ########.fr       */
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
