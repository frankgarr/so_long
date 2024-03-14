/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:30:44 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/14 14:52:03 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_images(t_map *map, t_win *mlx)
{
	int	i;

	i = -1;
	map->sprites = malloc (MAX_SPRITES * sizeof(t_data));
	if (!map->sprites)
		exit (ft_fd_printf(2, "%s", E_MALLOC) * 0 + 1);
	while (++i < MAX_SPRITES)
	{
		map->sprites[i].img = mlx_xpm_file_to_image(mlx->mlx, get_path(i), \
				&map->sprites[i].x, &map->sprites[i].y);
		if (open(get_path(i), O_RDONLY) == -1)
			exit(ft_fd_printf(2, "%s", E_OPEN) * 0 + 1);
	}
	return (0);
}
