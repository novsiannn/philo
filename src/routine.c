/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:39:44 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/24 11:20:23 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *phil)
{
	t_philo	*p;

	p = (t_philo *)phil;
	if (one_philo(p))
		return (NULL);
	p->start = time_now();
	if (p->id % 2)
		usleep(30000);
	if (p->params->check_tme && p->params->tme == p->iter)
		p->params->over = 1;
	while (!p->params->over)
	{
		if (ft_eat(p))
			break ;
		if (p->params->check_tme && p->iter == p->params->tme)
		{
			p->params->eated++;
			return (NULL);
		}
		if (ft_sleep(p))
			break ;
		if (ft_think(p))
			break ;
	}
	return (NULL);
}

int	ft_eat(t_philo *p)
{
	pthread_mutex_lock(p->forkl);
	if (p->params->over)
		return (put_down_forks(p));
	printf("%lld Philosopher %i has taken a fork\n", \
	time_now() - p->start, p->id);
	if (p->params->over)
		return (put_down_forks(p));
	pthread_mutex_lock(p->forkr);
	if (p->params->over)
		return (put_down_forks(p));
	printf("%lld Philosopher %i has taken a fork\n", \
	time_now() - p->start, p->id);
	if (p->params->over)
		return (put_down_forks(p));
	p->meal = time_now();
	p->iter++;
	printf("%lld Philosopher %i is eating\n", time_now() - p->start, p->id);
	while (p->meal + p->params->tte > time_now() && \
	!p->params->over)
		usleep(100);
	put_down_forks(p);
	return (0);
}

int	ft_sleep(t_philo *p)
{
	long long	time;

	time = time_now();
	if (p->params->over)
		return (put_down_forks(p));
	printf("%lld Philosopher %i is sleeping\n", time - p->start, p->id);
	while (time + p->params->tts > time_now() && !p->params->over)
		usleep(100);
	return (0);
}

int	ft_think(t_philo *p)
{
	if (p->params->over)
		return (1);
	printf("%lld Philosopher %i is thinking\n", time_now() - p->start, p->id);
	if (p->params->over)
		return (1);
	return (0);
}
