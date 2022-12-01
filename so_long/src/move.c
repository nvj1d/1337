/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:24:11 by mnajid            #+#    #+#             */
/*   Updated: 2022/04/23 00:21:51 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit(t_game *game)
{
	if (game->map->item == 0)
	{
		ft_game_drawer(game->map, game, game->img);
		free(game->map->map_array);
		game->map->map_array = NULL;
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		ft_printf("Adios!\n");
		exit(0);
	}
	else
		return ;
}

void	ft_move_up(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map_array;
	x = game->map->x;
	y = game->map->y;
	if (map[y - 1][x] != '1')
	{
		if (map[y - 1][x] == 'C')
			game->map->item--;
		if (map[y - 1][x] == 'E')
			ft_check_exit(game);
		else
		{
			map[y][x] = '0';
			map[y - 1][x] = 'P';
			game->map->y--;
			game->move_count++;
			ft_printf("mouve number: %d\n", game->move_count);
		}
	}
}

void	ft_move_down(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map_array;
	x = game->map->x;
	y = game->map->y;
	if (map[y + 1][x] != '1')
	{
		if (map[y + 1][x] == 'C')
			game->map->item--;
		if (map[y + 1][x] == 'E')
			ft_check_exit(game);
		else
		{
			map[y][x] = '0';
			map[y + 1][x] = 'P';
			game->map->y++;
			game->move_count++;
			ft_printf("mouve number: %d\n", game->move_count);
		}
	}
}

void	ft_move_right(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map_array;
	x = game->map->x;
	y = game->map->y;
	if (map[y][x + 1] != '1')
	{
		if (map[y][x + 1] == 'C')
			game->map->item--;
		if (map[y][x + 1] == 'E')
			ft_check_exit(game);
		else
		{
			map[y][x] = '0';
			map[y][x + 1] = 'P';
			game->map->x++;
			game->move_count++;
			ft_printf("mouve number: %d\n", game->move_count);
		}
	}
}

void	ft_move_left(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map_array;
	x = game->map->x;
	y = game->map->y;
	if (map[y][x - 1] != '1')
	{
		if (map[y][x - 1] == 'C')
			game->map->item--;
		if (map[y][x - 1] == 'E')
			ft_check_exit(game);
		else
		{
			map[y][x] = '0';
			map[y][x - 1] = 'P';
			game->map->x--;
			game->move_count++;
			ft_printf("mouve number: %d\n", game->move_count);
		}
	}
}
