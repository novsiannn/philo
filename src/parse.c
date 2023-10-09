/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:29:15 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/09 13:29:38 by nikitos          ###   ########.fr       */
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
