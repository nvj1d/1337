/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:24:14 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/18 10:29:58 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_check_eat(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (data->nb_eat_times > 0 \
		&& i < data->nb_philosophers && philo[i].nb_eat >= data->nb_eat_times)
		i++;
	if (i == data->nb_philosophers)
		data->eat_or_not = 1;
}

void	ft_death(t_data *data, t_philosopher *philo)
{
	int	i;

	while (!data->eat_or_not)
	{
		i = 0;
		while ((i < data->nb_philosophers) && !data->die)
		{
			pthread_mutex_lock(&(data->eating));
			if (ft_time() - philo[i].check_die_time > data->time_to_die)
			{
				ft_print(data, "died", i);
				data->die = 1;
			}
			pthread_mutex_unlock(&(data->eating));
			i++;
		}
		if (data->die)
			break ;
		if (data->nb_eat_times > 0)
			ft_check_eat(data, data->philo);
		usleep(100);
	}
}

void	ft_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philosophers)
		pthread_mutex_destroy(&(data->forks[i++]));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->printing));
}

int	ft_run(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	data->beginning_time = ft_time();
	while (i < data->nb_philosophers)
	{
		data->philo[i].check_die_time = ft_time();
		if (pthread_create(&data->philo[i].thread_id, NULL \
				, ft_routine, (void *)&(philo[i])))
			printf("thread not created");
		i++;
	}
	ft_death(data, data->philo);
	ft_end(data);
	return (0);
}
