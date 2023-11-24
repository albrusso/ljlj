/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:07:08 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/23 16:28:15 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/* LIBRARIES */

# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_data
{
	int				philo_nbr;
	useconds_t		time_die;
	useconds_t		time_eat;
	useconds_t		time_sleep;
	int				meals_nbr;
	int				stop_philo;
	pthread_mutex_t	m_printer;
	pthread_mutex_t	m_locker;
	pthread_mutex_t	*forks;
}		t_data;

typedef struct s_philo
{
	int				sit;
	useconds_t		time_last_meal;
	int				meal_counter;
	int				r_forks;
	int				l_forks;
	t_data			*data;
}		t_philo;

typedef struct s_storage
{
	t_data	*data;
	t_philo	*philos;
}		t_storage;

/* INIT.C */
t_storage	*ft_alloc_storage(void);
t_data		*ft_init_data(int _ac, char **_av);
int			ft_init_mutexs(t_data *_data);
t_philo		*ft_init_philo(t_data *_data);
pthread_t	*ft_alloc_thread(t_data *_data);

/* UTILS.C */
int			ft_atoi(const char *str);
int			ft_check_av(int _ac, char **_av);
useconds_t	ft_gettimeofday(void);
useconds_t	ft_time_print(void);
void		ft_printer(t_philo *_philo, char *msg);

/* THREAD.C */
void		ft_start_thread(t_storage *_storage, pthread_t *_thread);

/* ROUTINE.C */
void		*ft_routine(void *_philo);

#endif