/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:15:57 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/11 10:57:03 by frankgar         ###   ########.fr       */
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
		if (tmp && tmp[0] == '\n')
			exit(ft_fd_printf(2, "%s", E_CHARS) * 0 +1);
	}
	map = ft_split(map_one_line, '\n');
	free(map_one_line);
	return (map);
}

int	syntax(t_map *map, char **tmp_map, t_player *p)
{
	int	x;

	x = 0;
	while (tmp_map[map->len][x])
	{
		if (!ft_strchr("10CEP", tmp_map[map->len][x]))
			exit(ft_fd_printf(2, "%s", E_CHARS) * 0 +1);
		if ((!map->len || !x || !tmp_map[map->len][x + 1] || \
			!tmp_map[map->len + 1]) && tmp_map[map->len][x] != '1')
			exit(ft_fd_printf(2, "%s", E_NCLOSED) * 0 + 1);
		map->c_count += (tmp_map[map->len][x] == 'C');
		map->p_count += (tmp_map[map->len][x] == 'P');
		map->e_count += (tmp_map[map->len][x] == 'E');
		if (tmp_map[map->len][x++] == 'P')
		{
			p->x = x - 1;
			p->y = map->len;
			tmp_map[map->len][x - 1] = '0';
		}
	}
	if (map->len == 0)
		map->with = x;
	else if (x != map->with)
		exit(ft_fd_printf(2, "%s", E_NGRIP) * 0 + 1);
	return (0);
}

int	parsing(t_map *map, int fd, t_player *p)
{
	char		**tmp_map;

	tmp_map = get_map(fd);
	ft_bzero(map, sizeof(t_map));
	while (tmp_map[map->len])
	{
		syntax(map, tmp_map, p);
		map->len++;
	}
	if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1)
		exit(ft_fd_printf(2, "%s", E_CONTENT) * 0 + 1);
	ft_floodfill(tmp_map, *p);
	add_map(map, tmp_map);
	malloc_free_chars(tmp_map, map->len);
	return (1);
}
