/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:04:04 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/23 16:12:52 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_storage	*storage;
	pthread_t	*thread;

	storage = ft_alloc_storage();
	storage->data = ft_init_data(ac, av);
	storage->philos = ft_init_philo(storage->data);
	thread = ft_alloc_thread(storage->data);
	ft_start_thread(storage, thread);
	return (0);
}
