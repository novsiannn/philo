/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:18:46 by nikitos           #+#    #+#             */
/*   Updated: 2023/10/21 23:23:10 by nikitos          ###   ########.fr       */
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
	long long int	start;
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
void		join_threads(t_philo *philos);
void		free_all(t_philo *philo);

int			ft_eat(t_philo *p);
int			put_down_forks(t_philo *philos);
int			check_input(char **av);
int			check_death(t_philo *philos);
int			arg_is_number(char *arg);
int			ft_is_digit(char n);
int			ft_atoi(char *str);
int			ft_sleep(t_philo *p);
int			ft_think(t_philo *p);
int			one_philo(t_philo *philos);

t_data		*parse_data(char **av);

#endif