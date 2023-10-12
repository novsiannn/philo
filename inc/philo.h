/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:18:46 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/12 15:07:24 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_gdata
{
	int				ready;
	int				tte;
	int				ttd;
	int				tts;
	int				tme;
	int				over;
	int				num_p;
	int				check_tme;
	int				eated;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	pthread_t		thread;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_data			*params;
}				t_philo;

uint64_t	time_now(void);

void		incorrect_input(void);
void		ft_print(t_philo *p, int i);
void		ft_usleep(long int time);
void		*routine(void *phil);
void		create_threads(t_philo *philos);
void		init_philos(t_philo *philos, t_data *data);
void		init_mutex(t_philo *philos, t_data *data);
void		check_threads(t_philo *p);
void		ft_eat(t_philo *p);

int			check_input(char **av);
int			arg_is_number(char *arg);
int			ft_is_digit(char n);
int			ft_atoi(char *str);

t_data		*parse_data(char **av);

#endif