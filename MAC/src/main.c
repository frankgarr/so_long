/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:21:21 by frankgar          #+#    #+#             */
/*   Updated: 2024/04/25 11:17:42 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(int value)
{
	exit(value);
}

int	event(t_win *mlx)
{
	static int	offsets[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
	int			i;
	int			y;
	int			x;

	x = 0;
	y = 0;
	while (dox_items(mlx, &y, &x, 'C'))
	{
		i = -1;
		while (++i < 4)
		{
			if (mlx->map.map[(y + offsets[i][0])][(x + offsets[i][1])] == 'c')
			{
				mlx->map.map[(y + offsets[i][0])][(x + offsets[i][1])] = 'f';
				mlx->p.c_count++;
				mlx->event = 1;
			}
		}
		mlx->map.map[y][x] = 'F';
		x++;
	}
	while (dox_items(mlx, &y, &x, 'f'))
		mlx->map.map[y][x] = 'C';
	return (0);
}

int	render_game(t_win *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (mlx->event == 1)
		print_ilu(mlx);
	else if (mlx->map.map[mlx->p.y][mlx->p.x] == 'E')
		exit_window(0);
	mlx->event = 0;
	event(mlx);
	if (mlx->p.c_count == mlx->map.c_count)
	{
		if (dox_items(mlx, &y, &x, 'e') == 1)
		{
			mlx->map.map[y][x] = 'E';
			mlx->p.c_count++;
		}
	}
	return (0);
}

int	key_hook(int keycode, t_win *mlx)
{
	if (keycode == 53)
		exit_window(0);
	else if (keycode == 126 || keycode == 13)
		movement(mlx, (mlx->p.y - 1), mlx->p.x);
	else if (keycode == 124 || keycode == 2)
		movement(mlx, mlx->p.y, (mlx->p.x + 1));
	else if (keycode == 125 || keycode == 1)
		movement(mlx, (mlx->p.y + 1), mlx->p.x);
	else if (keycode == 123 || keycode == 0)
		movement(mlx, mlx->p.y, (mlx->p.x - 1));
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_win		mlx;

	fd = open(argv[1], O_RDONLY);
	ft_bzero(&mlx, sizeof(t_win));
	if (argc != 2)
		exit(ft_fd_printf(2, "%s%s", E_ARGS) * 0 + 1);
	if (!correct_file(argv[1]))
		exit(ft_fd_printf(2, "%s", E_FILE) * 0 + 1);
	if (fd < 0)
		exit(ft_fd_printf(2, "%s", E_OPEN) * 0 + 1);
	parsing(&mlx.map, fd, &mlx.p);
	if (close(fd))
		exit(ft_fd_printf(2, "%s", E_CLOSE) * 0 + 1);
	mlx.mlx = mlx_init();
	init_images(&mlx.map, &mlx);
	mlx.win = mlx_new_window(mlx.mlx,
			(32 * mlx.map.with), (32 * mlx.map.len + 25), "So_long");
	mlx.event = 1;
	put_base_map(&mlx);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_window, 0);
	mlx_loop_hook(mlx.mlx, render_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
