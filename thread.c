/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:53:32 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/24 14:35:39 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_thread(t_storage *_storage, pthread_t *_thread)
{
	int	i;

	i = 0;
	while (i < _storage->data->philo_nbr)
	{
		if (pthread_create(&_thread[i], NULL, ft_routine,
				&_storage->philos[i]) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < _storage->data->philo_nbr)
	{
		if (pthread_join(_thread[i], NULL) != 0)
			return ;
		i++;
	}
}
