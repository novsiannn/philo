/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:48:02 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/10 21:48:05 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_threads(t_philo *philos, t_data *data)
{
	init_mutex(philos, data);
	create_threads(philos);
	check_threads(philos);
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
	return (0);
}
