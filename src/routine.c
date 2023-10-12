/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:39:44 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/12 15:15:43 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *phil)
{
	t_philo *p;

	p = (t_philo *)phil;
	while (!(p->params->ready))
		continue ;
	if (p->id & 1)
		ft_usleep(p->params->tte * 0.9 + 1);
	while (!p->params->over)
	{
		ft_eat(p);
		pthread_mutex_lock(p->params->print);
		if (p->params->check_tme && \
			p->iter == p->params->tme)
		{
			p->params->eated++;
			pthread_mutex_unlock(p->params->print);
			return (NULL);
		}
		pthread_mutex_unlock(p->params->print);
		ft_print(p, 2);
		ft_usleep(p->params->tts);
		ft_print(p, 3);
	}
	return (NULL);
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->forkl);
	ft_print(p, 4);
	pthread_mutex_lock(p->forkr);
	ft_print(p, 4);
	p->meal = time_now();
	p->iter++;
	ft_print(p, 1);
	ft_usleep(p->params->tte);
	pthread_mutex_unlock(p->forkl);
	pthread_mutex_unlock(p->forkr);
}
