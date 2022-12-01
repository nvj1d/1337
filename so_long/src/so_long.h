/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:29:27 by mnajid            #+#    #+#             */
/*   Updated: 2022/03/07 20:29:27 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# define KEY_ESC 53

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define KEY_Q 12
# define KEY_E 14
# define KEY_R 15

//map struct:
typedef struct s_map{
	int		height;
	int		width;
	int		x;
	int		y;
	char	**map_array;
	int		startp;
	int		item;
	int		exit;
}t_map;

//image struct:
typedef struct s_img{
	void	*img_player;
	void	*img_coin;
	void	*img_grass;
	void	*img_door;
	void	*img_wall;
}t_img;

//the game struct:
typedef struct s_game{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_img	*img;
	void	*move_count;
}t_game;

//map functions:
void	ft_map_dim(char *path, t_map *map);
char	**ft_map_init(char *path, t_map *map);
void	ft_map_check(t_map *map);

//mouves functions:
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);

//graphic functions:
void	ft_drawer_init(t_game *game, t_img *img);
void	ft_game_drawer(t_map *map, t_game *game, t_img *img);

#endif