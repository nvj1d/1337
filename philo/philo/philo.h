/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:58:16 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/18 10:30:40 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	pthread_t		thread_id;
	int				nb_forks;
	int				rang;
	int				right_fork;
	int				left_fork;
	int				nb_eat;
	long long		check_die_time;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_data{
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat_times;
	int				die;
	int				eat_or_not;
	long long		beginning_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	printing;
	t_philosopher	*philo;
}	t_data;

//utils:
void		ft_erreur(int a);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_check_digits(char *str);
int			ft_args_digits(int argc, char **argv);
long long	ft_time(void);

//init:
int			ft_init_mutex(t_data *data);
int			ft_init_philo(t_data *data);
int			ft_check_positive(t_data *data);
int			ft_init(t_data *data, char **av, int ac);

//free:
void		ft_free(t_data *data);

//routine:
void		ft_print(t_data *data, char *str, int index);
void		ft_start_eating(t_data *data, t_philosopher *philo);
int			ft_take_fork(t_data *data, t_philosopher *philo);
void		*ft_routine(void *philo);

//run:
void		ft_check_eat(t_data *data, t_philosopher *philo);
void		ft_death(t_data *data, t_philosopher *philo);
void		ft_end(t_data *data);
int			ft_run(t_data *data, t_philosopher *philo);

#endif
