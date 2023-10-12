/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:48:02 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/12 15:10:56 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_threads(t_philo *philos, t_data *data)
{
	init_mutex(philos, data);
	create_threads(philos);
	check_threads(philos);
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

void	check_threads(t_philo *p)
{
	int	i;

	while (!p->params->ready)
		continue ;
	while (!p->params->over)
	{
		i = 0;
		while (i < p->params->num_p)
		{
			if (check_death(&p[i]))
				p->params->over = 1;
		}
		if (p->params->eated == p->params->num_p)
			p->params->over = 1;
	}
	return ;
}

void	join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->params->num_p)
	{
		pthread_join(philos[i].thread, (void *)&philos[i]);
		i++;
	}
}

void	free_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->params->num_p)
	{
		pthread_mutex_destroy(philo[i].forkl);
		i++;
	}
	pthread_mutex_destroy(philo->params->print);
	free(philo->params->print);
	free(philo->params->fork);
	free(philo->params);
	free(philo);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philos;

	if ((ac != 5 && ac != 6) || !check_input(av))
	{
		incorrect_input();
		exit(0);
	}
	philos = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	data = parse_data(av);
	init_philos(philos, data);
	init_threads(philos, data);
	join_threads(philos);
	return (0);
}
