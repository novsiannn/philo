/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:48:02 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/24 13:34:31 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_threads(t_philo *philos, t_data *data)
{
	init_mutex(philos, data);
	create_threads(philos);
	check_threads(philos);
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
	if (philos->params->check_tme && philos->params->tme == philos->iter)
		philos->params->over = 1;
	init_threads(philos, data);
	join_threads(philos);
	free_all(philos);
}
