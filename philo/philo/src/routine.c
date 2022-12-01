/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:24:09 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/05 17:21:43 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_data *data, char *str, int index)
{
	pthread_mutex_lock(&(data->printing));
	if (!data->die)
	{
		printf("%lld \t %d \t %s \n", \
			ft_time() - data->beginning_time, index + 1, str);
	}
	pthread_mutex_unlock(&(data->printing));
}

void	ft_start_eating(t_data *data, t_philosopher *philo)
{
	long	start;

	pthread_mutex_lock(&(data->eating));
	ft_print(data, "is eating ", philo->rang);
	philo->check_die_time = ft_time();
	pthread_mutex_unlock(&(data->eating));
	(philo->nb_eat)++;
	start = ft_time();
	while (ft_time() - start < data->time_to_eat)
		usleep(100);
}

int	ft_take_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	ft_print(data, "has taken a fork", philo->rang);
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	ft_print(data, "has taken a fork", philo->rang);
	ft_start_eating(data, philo);
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	if (data->eat_or_not)
		return (1);
	return (0);
}

void	*ft_routine(void *philo)
{
	t_philosopher	*copy;
	t_data			*data;
	long			start;

	copy = (t_philosopher *)philo;
	data = copy->data;
	if (data->nb_philosophers == 1)
	{
		ft_print(data, "has taking a fork", copy->rang);
		usleep(data->time_to_die * 1000);
		return (NULL);
	}
	if (copy->rang % 2)
		usleep(500);
	while (!data->die)
	{
		if (ft_take_fork(data, copy))
			break ;
		ft_print(data, "sleeping ", copy->rang);
		start = ft_time();
		while (ft_time() - start < data->time_to_sleep)
			usleep(100);
		ft_print(data, "thinking", copy->rang);
	}
	return ((void *)0);
}
