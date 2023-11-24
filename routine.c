/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:56:52 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/24 14:45:20 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_drop_forks(t_philo *_philo, t_data *_data_clone)
{
	int	l_f;
	int	r_f;

	r_f = _philo->r_forks;
	l_f = _philo->l_forks;
	pthread_mutex_unlock(&_data_clone->forks[r_f]);
	pthread_mutex_unlock(&_data_clone->forks[l_f]);
}

void	ft_take_forks(t_philo *_philo, t_data *_data_clone)
{
	int		r_f;
	int		l_f;

	r_f = _philo->r_forks;
	l_f = _philo->l_forks;
	pthread_mutex_lock(&_data_clone->forks[l_f]);
	ft_printer(_philo, "has take fork");
	pthread_mutex_lock(&_data_clone->forks[r_f]);
	ft_printer(_philo, "has take fork");
}

void	ft_eat(t_philo *_philo)
{
	t_data	*_data_clone;

	_data_clone = _philo->data;
	ft_take_forks(_philo, _data_clone);
	usleep(_data_clone->time_eat * 1000);
	ft_printer(_philo, "is eating");
	pthread_mutex_lock(&_philo->data->m_locker);
	_philo->meal_counter += 1;
	_philo->time_last_meal = ft_time_print();
	pthread_mutex_unlock(&_philo->data->m_locker);
	ft_drop_forks(_philo, _data_clone);
}

void	*ft_routine(void *_philo)
{
	t_philo	*philo;
	t_data	*data_clone;

	if (!_philo)
		return (NULL);
	philo = (t_philo *)_philo;
	data_clone = philo->data;
	while (1)
	{
		pthread_mutex_lock(&philo->data->m_locker);
		if (data_clone->meals_nbr > 0
			&& (philo->meal_counter == data_clone->meals_nbr))
		{
			pthread_mutex_unlock(&philo->data->m_locker);
			break ;
		}
		pthread_mutex_unlock(&philo->data->m_locker);
		ft_eat(philo);
		usleep(data_clone->time_sleep * 1000);
		ft_printer(philo, "is sleeping");
	}
	return (NULL);
}
