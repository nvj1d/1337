/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:38:38 by mnajid            #+#    #+#             */
/*   Updated: 2022/07/05 13:33:18 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (1);
		if (ft_args_digits(ac, av) == 1 || ft_init(data, av, ac) == 1)
		{
			ft_free(data);
			printf("please check the values and try again!\n");
			return (1);
		}
		ft_run(data, data->philo);
		ft_free(data);
	}
	else
	{
		printf("the syntax is: NF ttd tte tts [Ntfe]\n");
	}
}
