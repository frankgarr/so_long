/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:15:57 by frankgar          #+#    #+#             */
/*   Updated: 2024/02/25 11:25:49 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	correct_file(char *pfile)
{
	int	i;

	i = 0;
	while (pfile[i] != '.' && pfile[i])
		i++;
	if (pfile[i] == '.' && pfile[i + 1] == 'b' && \
			pfile[i + 2] == 'e' && pfile[i + 3] == 'r')
		return (1);
	return (0);
}

char	**get_map(int fd)
{
	char	*tmp;
	char	*map_tmp;
	char	*map_one_line;
	char	**map;

	tmp = NULL;
	map_one_line = NULL;
	while (tmp || !map_one_line)
	{
		map_tmp = map_one_line;
		if (tmp)
		{
			map_one_line = ft_strjoin(map_tmp, tmp);
			free(tmp);
			free(map_tmp);
		}
		tmp = get_next_line(fd);
	}
	map = ft_split(map_one_line, '\n');
	free(map_one_line);
	return (map);
}

int	syntax(t_map *map, int y, t_player *p)
{
	int	x;

	x = -1;
	while (map->map[y][++x])
	{
		if (!ft_strchr("10CEP", map->map[y][x]))
			exit(ft_fd_printf(2, "Error\nUnexpected Map Characters Found.\n") \
					* 0 +1);
		if ((!y || !x || !map->map[y][x + 1] || !map->map[y + 1]) &&
				map->map[y][x] != '1')
			exit(ft_fd_printf(2, "Error\nMap Not Closed.\n") * 0 + 1);
		map->c_count += (map->map[y][x] == 'C');
		map->p_count += (map->map[y][x] == 'P');
		map->e_count += (map->map[y][x] == 'E');
		if (map->map[y][x] == 'P')
		{
			p->x = x;
			p->y = y;
		}
	}
	if (y == 0)
		map->map_len = x;
	else if (x != map->map_len)
		exit(ft_fd_printf(2, "Error\nMap Doesn't Have a Grid Shape.\n") * 0 +1);
	return (0);
}

int	parsing(int fd)
{
	t_map		map;
	t_player	p;
	int			y;

	y = 0;
	ft_bzero(&map, sizeof(t_map));
	map.map = get_map(fd);
	while (map.map[y])
		syntax(&map, y++, &p);
	if (map.p_count != 1 || map.e_count != 1 || map.c_count < 1)
		exit(ft_fd_printf(2, "Error\nAmount On The Map Content Is Not Right.\n")
			* 0 + 1);
	ft_floodfill(&map, p);
	return (1);
}
