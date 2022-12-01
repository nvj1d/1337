/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:27:07 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/07 20:27:07 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_init_game(t_game *game, t_map *map, t_img *img)
{
	game->move_count = 0;
	game->map = map;
	game->img = img;
	game->mlx_ptr = mlx_init();
}

int	ft_exit_handler(t_game *game)
{
	t_game	*tmp;

	tmp = game;
	free(tmp->map->map_array);
	tmp->map->map_array = NULL;
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

int	ft_key_handler(int key, t_game *game)
{
	t_game	*tmp;
	char	**map;

	tmp = game;
	map = game->map->map_array;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (key == KEY_ESC)
		ft_exit_handler(game);
	else if (key == KEY_W)
		ft_move_up(game);
	else if (key == KEY_S)
		ft_move_down(game);
	else if (key == KEY_A)
		ft_move_left(game);
	else if (key == KEY_D)
		ft_move_right(game);
	ft_game_drawer(game->map, game, game->img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;
	t_img	img;
	int		h;
	int		w;

	if (argc == 2)
	{
		map.map_array = ft_map_init(argv[1], &map);
		if (!map.map_array)
			return (0);
		ft_map_check(&map);
		ft_init_game(&game, &map, &img);
		h = map.height * 50;
		w = map.width * 50;
		game.win_ptr = mlx_new_window(game.mlx_ptr, w, h, "let's dance!" );
		ft_drawer_init(&game, &img);
		ft_game_drawer(&map, &game, &img);
		mlx_hook(game.win_ptr, 02, 0, ft_key_handler, &game);
		mlx_hook(game.win_ptr, 17, 0, ft_exit_handler, &game);
		mlx_loop(game.mlx_ptr);
	}
	else
		ft_printf("the syntax is : ./so_long map\n");
	return (0);
}
