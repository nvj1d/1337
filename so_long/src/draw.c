/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:55:39 by mnajid            #+#    #+#             */
/*   Updated: 2022/04/27 21:02:53 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drawer_init(t_game *game, t_img *img)
{
	int		s;
	void	*p;

	s = 50;
	p = game->mlx_ptr;
	img->img_wall = mlx_xpm_file_to_image(p, "./assets/wall.xpm", &s, &s);
	img->img_grass = mlx_xpm_file_to_image(p, "./assets/grass.xpm", &s, &s);
	img->img_coin = mlx_xpm_file_to_image(p, "./assets/coin.xpm", &s, &s);
	img->img_player = mlx_xpm_file_to_image(p, "./assets/plyr.xpm", &s, &s);
	img->img_door = mlx_xpm_file_to_image(p, "./assets/door.xpm", &s, &s);
}

void	ft_put_image(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, j * 50, i * 50);
}

void	ft_game_drawer(t_map *map, t_game *game, t_img *img)
{
	int		i;
	int		j;
	char	**map_arr;

	map_arr = map->map_array;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_array[i][j] == '1')
				ft_put_image(game, img->img_wall, i, j);
			else if (map->map_array[i][j] == '0')
				ft_put_image(game, img->img_grass, i, j);
			else if (map->map_array[i][j] == 'C')
				ft_put_image(game, img->img_coin, i, j);
			else if (map->map_array[i][j] == 'P')
				ft_put_image(game, img->img_player, i, j);
			else if (map->map_array[i][j] == 'E')
				ft_put_image(game, img->img_door, i, j);
		}
	}
}
