/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:23:34 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/13 13:04:15 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//ft_printf("PLAYER[%d][%d]  [%c]  ---> [%c]   [%d][%d]\n", mlx->p.y, mlx->p.x, mlx->map.map[mlx->p.y][mlx->p.x], mlx->map.map[y][x], y, x);
int	movement(t_win *mlx, int y, int x)
{
	mlx->event = 1;
	mlx->p.sprite = ((y - mlx->p.y == -1 && x - mlx->p.x == 0) * PJ_BACK);
	mlx->p.sprite += ((y - mlx->p.y == 0 && x - mlx->p.x == 1) * PJ_RIGHT);
	mlx->p.sprite += ((y - mlx->p.y == 1 && x - mlx->p.x == 0) * PJ_UP);
	mlx->p.sprite += ((y - mlx->p.y == 0 && x - mlx->p.x == -1) * PJ_LEFT);
	if (MANDATORI == 1 && (mlx->map.map[y][x] != '1'
				&& mlx->map.map[y][x] != 'c' && mlx->map.map[y][x] != 'C'))
	{ 
		mlx->p.y = y;
		mlx->p.x = x;
		mlx->p.moves++;
		ft_printf("Moves --> %d\n", mlx->p.moves);
	}
	else if (MANDATORI == 0 && ((!y || !x || !mlx->map.map[y][x + 1] \
			|| !mlx->map.map[y + 1][x]) && mlx->map.map[y][x] != 'c'))
	{
		mlx->p.y = y;
		mlx->p.x = x;
		mlx->p.moves++;
		ft_printf("Moves --> %d\n", mlx->p.moves);
	}
	if (mlx->map.map[y][x] == 'E')
		mlx->event = 3;
	return (1);
}

int	print_img(t_win *mlx, int y, int x, int n)
{
	y = y * 32 + 25;
	x = x * 32;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.sprites[n].img, x, y);
	return (0);
}

int print_set_of_Walls(t_win *mlx, int y, int x)
{
	if (mlx->map.map[y][x] == '1')
		print_img(mlx, y, x, HOLE_3);
	if (y == 0 && x != 0)
		print_img(mlx, y, x, WALL_U3);
	if (y != 0 && x == 0)
		print_img(mlx, y, x, WALL_L3);
	if (x + 1 == mlx->map.with)
		print_img(mlx, y, x, WALL_R3);
	if (y + 1 == mlx->map.len)
		print_img(mlx, y, x, WALL_D3);
	if (y == 0 && x == 0)
		print_img(mlx, y, x, WALL_UL3);
	if (y == 0 && x + 1 == mlx->map.with)
		print_img(mlx, y, x, WALL_UR3);
	if (y + 1 == mlx->map.len && x == 0)
		print_img(mlx, y, x, WALL_DL3);
	if (y + 1 == mlx->map.len && x + 1 == mlx->map.with)
		print_img(mlx, y, x, WALL_DR3);
	return (1);
}

int	put_base_map(t_win *mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mlx->map.len)
	{
		x = -1;
		while (++x < mlx->map.with)
		{
			print_img(mlx, y, x, FLOOR_3);
			print_set_of_Walls(mlx, y, x);
		}
	}
	return (1);
}	
//mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.sprites[mlx->p.sprite].img, mlx->p.x * 32, mlx->p.y * 32);
