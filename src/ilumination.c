/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilumination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:23:57 by frankgar          #+#    #+#             */
/*   Updated: 2024/04/19 12:19:48 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_ilu3(t_win *mlx, int y, int x)
{
	if (y < 0 || x < 0 || x >= mlx->map.with || y >= mlx->map.len)
		return (-1);
	if (mlx->map.map[y][x] == '1' && decide_ilu(mlx, y, x) == 3)
	{
		print_img(mlx, y, x, HOLE_3);
		if (y == 0)
			print_img(mlx, y, x, WALL_U3);
		else if (y + 1 == mlx->map.len)
			print_img(mlx, y, x, WALL_D3);
		else if (x + 1 == mlx->map.with)
			print_img(mlx, y, x, WALL_R3);
		else if (x == 0)
			print_img(mlx, y, x, WALL_L3);
		else if (x == 0 && y == 0)
			print_img(mlx, y, x, WALL_UL3);
		else if (x == 0 && y + 1 == mlx->map.len)
			print_img(mlx, y, x, WALL_DL3);
		else if (x + 1 == mlx->map.with && y + 1 == mlx->map.len)
			print_img(mlx, y, x, WALL_DR3);
		else if (x + 1 == mlx->map.with && y == 0)
			print_img(mlx, y, x, WALL_UR3);
	}
	else if (decide_ilu(mlx, y, x) == 3)
		print_img(mlx, y, x, FLOOR_3);
	return (0);
}

int	put_ilu2(t_win *mlx, int y, int x)
{
	if (y < 0 || x < 0 || x >= mlx->map.with || y >= mlx->map.len
		|| decide_ilu(mlx, y, x) != 2)
		return (-1);
	if (mlx->map.map[y][x] == ' ')
		print_img(mlx, y, x, FLOOR_2);
	else if (mlx->map.map[y][x] == '1')
		print_walls2(mlx, y, x);
	else if (mlx->map.map[y][x] == 'e')
		print_img(mlx, y, x, EXIT_C2);
	else if (mlx->map.map[y][x] == 'E')
		print_img(mlx, y, x, EXIT_O2);
	else if (mlx->map.map[y][x] == 'c')
		print_img(mlx, y, x, TORCH_C2);
	else if (mlx->map.map[y][x] == 'C')
		print_img(mlx, y, x, TORCH_O1);
	else if (mlx->map.map[y][x] == 'F')
		print_img(mlx, y, x, TORCH_O1);
	return (0);
}

int	put_ilu1(t_win *mlx, int y, int x)
{
	if (y < 0 || x < 0 || x >= mlx->map.with || y >= mlx->map.len)
		return (-1);
	if (mlx->map.map[y][x] == ' ')
		print_img(mlx, y, x, FLOOR_1);
	else if (mlx->map.map[y][x] == '1')
		print_walls1(mlx, y, x);
	else if (mlx->map.map[y][x] == 'e')
		print_img(mlx, y, x, EXIT_C1);
	else if (mlx->map.map[y][x] == 'E')
		print_img(mlx, y, x, EXIT_O1);
	else if (mlx->map.map[y][x] == 'c')
		print_img(mlx, y, x, TORCH_C1);
	else if (mlx->map.map[y][x] == 'C')
		print_img(mlx, y, x, TORCH_O1);
	else if (mlx->map.map[y][x] == 'F')
		print_img(mlx, y, x, TORCH_O1);
	return (0);
}

int	set_ilu(t_win *mlx, int y, int x, int ilu)
{
	static int	offsets1[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
	static int	offsets2[8][2] = {{1, 1}, {0, 2}, {2, 0}, {1, -1}, {0, -2}, \
												{-1, -1}, {-2, 0}, {-1, 1}};
	static int	offsets3[12][2] = {{3, 0}, {0, 3}, {-3, 0}, {0, -3}, {2, 1}, \
			{2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-1, 2}, {-1, -2}, {-2, -1}};
	int			i;

	i = -1;
	if (ilu == 1)
		while (++i < 5)
			put_ilu1(mlx, y + offsets1[i][0], x + offsets1[i][1]);
	else if (ilu == 2)
		while (++i < 8)
			put_ilu2(mlx, y + offsets2[i][0], x + offsets2[i][1]);
	else if (ilu == 3)
		while (++i < 12)
			put_ilu3(mlx, y + offsets3[i][0], x + offsets3[i][1]);
	return (1);
}

int	print_ilu(t_win *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	set_ilu(mlx, mlx->p.y, mlx->p.x, 3);
	set_ilu(mlx, mlx->p.y, mlx->p.x, 2);
	while (dox_items(mlx, &y, &x, 'C') != 0)
		set_ilu(mlx, y, x++, 2);
	while (dox_items(mlx, &y, &x, 'E') != 0)
		set_ilu(mlx, y, x++, 2);
	while (dox_items(mlx, &y, &x, 'C') != 0)
		set_ilu(mlx, y, x++, 1);
	while (dox_items(mlx, &y, &x, 'E') != 0)
		set_ilu(mlx, y, x++, 1);
	set_ilu(mlx, mlx->p.y, mlx->p.x, 1);
	print_img(mlx, mlx->p.y, mlx->p.x, mlx->p.sprite);
	return (0);
}
