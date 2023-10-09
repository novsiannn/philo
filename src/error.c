/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:32:24 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/09 12:13:09 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	incorrect_input(void)
{
	printf("Incorrect input!\n\nHere are rules to run programm:\n\n");
	printf("./philo | number_of_philosophers | time_to_die ");
	printf("| time_to_eat | time_to_sleep |");
	printf(" [number_of_times_each_philosopher_must_eat]\n");
}
