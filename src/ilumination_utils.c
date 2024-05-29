/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilumination_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:05:36 by frankgar          #+#    #+#             */
/*   Updated: 2024/04/18 12:01:41 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	decide_ilu(t_win *mlx, int y, int x)
{
	static int	set[13][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}, \
		{1, 1}, {0, 2}, {2, 0}, {1, -1}, {0, -2}, {-1, -1}, {-2, 0}, {-1, 1}};
	int			i;
	char		c;

	i = -1;
	while (++i < 13)
	{
		if (!(y + set[i][0] < 0 || x + set[i][1] < 0
			|| x + set[i][1] >= mlx->map.with || y + set[i][0] >= mlx->map.len))
		{
			c = mlx->map.map[y + set[i][0]][x + set[i][1]];
			if (c == 'C' || c == 'F' || c == 'E'
				|| (x + set[i][1] == mlx->p.x && y + set[i][0] == mlx->p.y))
			{
				if (i < 5)
					return (1);
				return (2);
			}
		}
	}
	return (3);
}

int	dox_items(t_win *mlx, int *y, int *x, char c)
{
	while (*y < mlx->map.len)
	{
		while (*x < mlx->map.with)
		{
			if (mlx->map.map[*y][*x] == c)
				return (1);
			*x += 1;
		}
		*x = 0;
		*y += 1;
	}
	*x = 0;
	*y = 0;
	return (0);
}

int	print_walls2(t_win *mlx, int y, int x)
{
	print_img(mlx, y, x, HOLE_2);
	if (x + 1 == mlx->map.with && y == 0)
		print_img(mlx, y, x, WALL_UR2);
	else if (y + 1 == mlx->map.len && x != 0 && x + 1 != mlx->map.with)
		print_img(mlx, y, x, WALL_D2);
	else if (x + 1 == mlx->map.with && y != 0 && y + 1 != mlx->map.len)
		print_img(mlx, y, x, WALL_R2);
	else if (x == 0 && y != 0 && y + 1 != mlx->map.len)
		print_img(mlx, y, x, WALL_L2);
	else if (x == 0 && y == 0)
		print_img(mlx, y, x, WALL_UL2);
	else if (x == 0 && y + 1 == mlx->map.len)
		print_img(mlx, y, x, WALL_DL2);
	else if (x + 1 == mlx->map.with && y + 1 == mlx->map.len)
		print_img(mlx, y, x, WALL_DR2);
	else if (y == 0 && x != 0 && x + 1 != mlx->map.with)
		print_img(mlx, y, x, WALL_U2);
	return (0);
}

int	print_walls1(t_win *mlx, int y, int x)
{
	if (y == 0)
		print_img(mlx, y, x, WALL_U1);
	else if (y + 1 == mlx->map.len)
		print_img(mlx, y, x, WALL_D1);
	else if (x + 1 == mlx->map.with)
		print_img(mlx, y, x, WALL_R1);
	else if (x == 0)
		print_img(mlx, y, x, WALL_L1);
	else
		print_img(mlx, y, x, HOLE_1);
	return (0);
}
