/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:39:44 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/27 17:32:13 by nikitos          ###   ########.fr       */
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
		ft_usleep(p->params->tte * 0.9 + 1);
	while (!p->params->over)
	{
		if (ft_eat(p))
			break ;
		if (p->params->check_tme && p->iter == p->params->tme)
		{
			pthread_mutex_lock(p->params->print);
			p->params->eated++;
			pthread_mutex_unlock(p->params->print);
			return (NULL);
		}
		if (ft_sleep(p))
			break ;
		if (ft_think(p))
			break ;
	}
	return (NULL);
}

int	locking_forks(t_philo *p)
{
	pthread_mutex_lock(p->forkl);
	if (p->params->over)
		return (put_down_forks(p));
	pthread_mutex_lock(p->params->print);
	if (!p->params->over)
		printf("%lld Philosopher %i has taken a fork\n", \
	time_now() - p->start, p->id);
	pthread_mutex_unlock(p->params->print);
	if (p->params->over)
		return (put_down_forks(p));
	pthread_mutex_lock(p->forkr);
	if (p->params->over)
		return (put_down_forks(p));
	pthread_mutex_lock(p->params->print);
	if (!p->params->over)
		printf("%lld Philosopher %i has taken a fork\n", \
	time_now() - p->start, p->id);
	pthread_mutex_unlock(p->params->print);
	if (p->params->over)
		return (put_down_forks(p));
	return (0);
}

int	ft_eat(t_philo *p)
{
	if (locking_forks(p) == 1)
		return (1);
	p->meal = time_now();
	p->iter++;
	pthread_mutex_lock(p->params->print);
	if (!p->params->over)
		printf("%lld Philosopher %i is eating\n", time_now() - p->start, p->id);
	pthread_mutex_unlock(p->params->print);
	while ((unsigned long long)p->meal + (unsigned long long)p->params->tte \
	> time_now() && !p->params->over)
		usleep(100);
	put_down_forks(p);
	return (0);
}

int	ft_sleep(t_philo *p)
{
	unsigned long long	time;

	time = time_now();
	if (p->params->over)
		return (put_down_forks(p));
	pthread_mutex_lock(p->params->print);
	if (!p->params->over)
		printf("%lld Philosopher %i is sleeping\n", time - p->start, p->id);
	pthread_mutex_unlock(p->params->print);
	while (time + p->params->tts > time_now() && !p->params->over)
		usleep(100);
	return (0);
}

int	ft_think(t_philo *p)
{
	if (p->params->over)
		return (1);
	pthread_mutex_lock(p->params->print);
	if (!p->params->over)
		printf("%lld Philosopher %i is thinking\n", \
		time_now() - p->start, p->id);
	pthread_mutex_unlock(p->params->print);
	if (p->params->over)
		return (1);
	return (0);
}
