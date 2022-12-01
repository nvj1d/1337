/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 14:02:15 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/18 10:28:47 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(data->eating), NULL))
		return (1);
	if (pthread_mutex_init(&(data->printing), NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->nb_philosophers));
	if (data->forks == NULL)
		return (1);
	while (i < data->nb_philosophers)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_data) * data->nb_philosophers);
	if (data->philo == NULL)
		return (1);
	while (i < data->nb_philosophers)
	{
		data->philo[i].rang = i;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philosophers;
		data->philo[i].nb_eat = 0;
		data->philo[i].check_die_time = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	ft_check_positive(t_data *data)
{
	if (data->nb_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (1);
	return (0);
}

int	ft_init(t_data *data, char **av, int ac)
{
	data->nb_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->nb_eat_times = ft_atoi(av[5]);
		if (data->nb_eat_times <= 0)
			return (1);
	}
	data->die = 0;
	data->eat_or_not = 0;
	data->beginning_time = 0;
	if (ft_check_positive(data))
		return (1);
	if (ft_init_mutex(data) || ft_init_philo(data))
		return (1);
	return (0);
}
