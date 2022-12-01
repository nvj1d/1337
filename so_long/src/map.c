/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:26:05 by mnajid            #+#    #+#             */
/*   Updated: 2022/04/23 00:52:59 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_extention_valid(char *path)
{
	int		path_end;
	char	*ending;
	char	*validpath;

	path_end = ft_strlen(path) - 4;
	ending = ".ber";
	validpath = "src/maps/";
	if (ft_strncmp(ending, &path[path_end], 4) != 0)
	{
		ft_printf("the extention must be - .ber - !\n");
		exit(0);
	}
	if (ft_strncmp(validpath, path, 9) != 0)
	{
		ft_printf("invalid map path!\n");
		ft_printf("the correct path is ./src/maps/map_name.ber\n");
		exit(0);
	}
}

void	ft_map_dim(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0)
			map->width = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->height = i;
}

char	**ft_map_init(char *path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	**map_arr;

	ft_extention_valid(path);
	ft_map_dim(path, map);
	map_arr = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map_arr)
		return (NULL);
	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map_arr[i] = ft_strdup(line);
		if (!map_arr[i])
			return (NULL);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map_arr[map->height] = NULL;
	close(fd);
	return (map_arr);
}
