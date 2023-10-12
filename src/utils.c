/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:04:41 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/10 21:31:08 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print(t_philo *p, int i)
{
	pthread_mutex_lock(p->params->print);
	if (p->params->over)
	{
		pthread_mutex_unlock(p->params->print);
		return ;
	}
	if (i == 1)
		printf("%llu %d is eating\n", time_now() - p->start, p->id);
	else if (i == 2)
		printf("%llu %d is sleeping\n", time_now() - p->start, p->id);
	else if (i == 3)
		printf("%llu %d is thinking\n", time_now() - p->start, p->id);
	else if (i == 4)
		printf("%llu %d took a fork\n", time_now() - p->start, p->id);
	else if (i == 5)
		printf("%llu %d died\n", time_now() - p->start, p->id);
	pthread_mutex_unlock(p->params->print);
}

uint64_t	time_now(void)
{
	uint64_t		milliseconds;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < (unsigned long long) time)
		usleep(150);
}

int	ft_atoi(char *str)
{
	int i;
	int sum;
	int sign;

	sign = 1;
	sum = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	sum *= sign;
	return (sum);
}
