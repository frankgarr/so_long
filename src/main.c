/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:21:21 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/13 13:04:32 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exit_window(t_win *mlx)
{
	(void)mlx;
	//limpiar toda la memoria`
	exit(0);
}

int event(t_win *mlx)
{
	static int	offsets[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
	int			flag;
	int			i;
	int			y;
	int			x;

	i = -1;
	flag = 0;
	while (++i < 5)
	{
		y = mlx->p.y + offsets[i][0];
		x = mlx->p.x + offsets[i][1];
		if (mlx->map.map[y][x] == 'c')
		{
			mlx->map.map[y][x] = 'C';
			mlx->p.c_count++;
		}
	}
	x = 0;
	y = 0;
	if (mlx->p.c_count == mlx->map.c_count)
		if (dox_items(mlx, &y, &x, 'e') == 1)
		{
			mlx->map.map[y][x] = 'E';
			mlx->p.c_count++;
		}
	return (0);
}

int render_game(t_win *mlx)
{
	if (mlx->event == 1)
	{
		event(mlx);
		print_ilu(mlx);
	}
	else if (mlx->event == 2)
	{
		put_base_map(mlx);
		print_ilu(mlx);
	}
	else if (mlx->event == 3)
	{
		ft_printf("YUPI eralono's WIN\n");
		exit(0);
		//exit_window;
	}
	mlx->event = 0;
	return (0);
}

int	key_hook(int keycode, t_win *mlx)
{
	if (keycode == 53)
		exit_window(mlx);
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
		exit(ft_fd_printf(2, "%s", E_ARGS) * 0 + 1);
	if (!correct_file(argv[1]))
		exit(ft_fd_printf(2, "%s", E_FILE) * 0 + 1);
	if (fd < 0)
		exit(ft_fd_printf(2, "%s", E_OPEN) * 0 + 1);
	parsing(&mlx.map, fd, &mlx.p);
	close(fd);
	mlx.mlx = mlx_init();
	init_images(&mlx.map, &mlx);
	mlx.win = mlx_new_window(mlx.mlx,
			(32 * mlx.map.with), (32 * mlx.map.len + 25), "So_long");
	mlx.event = 2;
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_window, &mlx);
	mlx_loop_hook(mlx.mlx, render_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
//mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->map.sprites[mlx->p.sprite].img, 5, 5);

