/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:37:45 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/09 12:13:06 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arg_is_number(char *arg)
{
	int	i;

	i = 0;
	while ((arg[i] && ft_is_digit(arg[i])) || arg[i] == '+')
	{
		if (arg[i] == '+')
		{
			i++;
			if (!ft_is_digit(arg[i]))
				return (0);
		}
		i++;
	}
	if (arg[i] != '\0' && !ft_is_digit(arg[i]))
		return (0);
	return (1);
}

int	ft_is_digit(char n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}
