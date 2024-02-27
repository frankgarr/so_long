/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:11:52 by frankgar          #+#    #+#             */
/*   Updated: 2024/02/25 11:19:46 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_fill(t_map *map, int x, int y)
{
	if (!ft_strchr("0CEP", map->map[y][x]))
		return (0);
	else if (map->map[y][x] == '0')
		map->map[y][x] = ' ';
	else if (map->map[y][x] == 'E')
		map->map[y][x] = 'e';
	else if (map->map[y][x] == 'C')
		map->map[y][x] = 'c';
	map_fill(map, x, y + 1);
	map_fill(map, x + 1, y);
	map_fill(map, x - 1, y);
	map_fill(map, x, y - 1);
	return (1);
}

int	ft_floodfill(t_map *map, t_player p)
{
	int	y;
	int	x;

	y = 0;
	map_fill(map, p.x, p.y);
	while (map->map[y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'E' || map->map[y][x] == 'C')
				exit(ft_fd_printf(2, "Error\nImpossible Map\n") * 0 + 1);
			else if (map->map[y][x] == '0')
				map->map[y][x] = ' ';
		}
		y++;
	}
	y = 0;
	while (map->map[y])
		ft_printf("%s\n", map->map[y++]);
	return (1);
}
