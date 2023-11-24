/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:08:21 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/24 14:27:14 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_storage	*ft_alloc_storage(void)
{
	t_storage	*_storage;

	_storage = (t_storage *)malloc(sizeof(t_storage));
	if (!_storage)
		return (NULL);
	return (_storage);
}

t_data	*ft_init_data(int _ac, char **_av)
{
	t_data	*_data;

	_data = (t_data *)malloc(sizeof(t_data));
	if (!_data || ft_check_av(_ac, _av) == 0)
		return (NULL);
	_data->philo_nbr = ft_atoi(_av[1]);
	_data->time_die = ft_atoi(_av[2]);
	_data->time_eat = ft_atoi(_av[3]);
	_data->time_sleep = ft_atoi(_av[4]);
	_data->stop_philo = 0;
	if (_ac == 6)
		_data->meals_nbr = ft_atoi(_av[5]);
	else
		_data->meals_nbr = -1;
	if (ft_init_mutexs(_data) == 0)
		return (NULL);
	return (_data);
}

int	ft_init_mutexs(t_data *_data)
{
	int	i;

	_data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* _data->philo_nbr);
	if (!_data->forks)
		return (0);
	i = 0;
	while (i < _data->philo_nbr)
	{
		if (pthread_mutex_init(&_data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&_data->m_locker, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&_data->m_printer, NULL) != 0)
		return (0);
	return (1);
}

t_philo	*ft_init_philo(t_data *_data)
{
	t_philo	*_philo;
	int		i;

	_philo = (t_philo *)malloc(sizeof(t_philo) * _data->philo_nbr);
	if (!_philo)
		return (NULL);
	i = 0;
	while (i < _data->philo_nbr)
	{
		_philo[i].sit = i + 1;
		_philo[i].time_last_meal = 0;
		_philo[i].meal_counter = 0;
		_philo[i].l_forks = i;
		_philo[i].r_forks = (i + 1) % _data->philo_nbr;
		_philo[i].data = _data;
		i++;
	}
	return (_philo);
}

pthread_t	*ft_alloc_thread(t_data *_data)
{
	pthread_t	*_thread;

	_thread = (pthread_t *)malloc(sizeof(pthread_t) * _data->philo_nbr);
	if (!_thread)
		return (NULL);
	return (_thread);
}
