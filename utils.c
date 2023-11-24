/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:12:58 by albrusso          #+#    #+#             */
/*   Updated: 2023/11/24 14:37:21 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	i = 0;
	sign = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (sign == -1 || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_check_av(int _ac, char **_av)
{
	int	i;
	int	j;

	i = 1;
	while (i < _ac)
	{
		j = 0;
		while (_av[i][j])
		{
			if (_av[i][j] < '0' && _av[i][j] > '9')
				return (0);
			j++;
		}
		if (ft_atoi(_av[i]) < 1)
			return (0);
		i++;
	}
	return (1);
}

useconds_t	ft_gettimeofday(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return ((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
}

useconds_t	ft_time_print(void)
{
	static useconds_t	time;

	if (time == 0)
		time = ft_gettimeofday();
	return (ft_gettimeofday() - time);
}

void	ft_printer(t_philo *_philo, char *msg)
{
	int	i;

	pthread_mutex_lock(&_philo->data->m_locker);
	i = _philo->data->stop_philo;
	pthread_mutex_unlock(&_philo->data->m_locker);
	pthread_mutex_lock(&_philo->data->m_printer);
	if (i == 0)
	{
		pthread_mutex_lock(&_philo->data->m_locker);
		printf("[%u] %d %s\n", ft_time_print(), _philo->sit, msg);
		pthread_mutex_unlock(&_philo->data->m_locker);
	}
	pthread_mutex_unlock(&_philo->data->m_printer);
}
