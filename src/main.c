/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:21:21 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/12 13:04:51 by frankgar         ###   ########.fr       */
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
	int	flag;

	flag = 0;
	if (mlx->map.map[mlx->p.y + 1][mlx->p.x] == 'c')
	{
		mlx->map.map[mlx->p.y + 1][mlx->p.x] = 'C';
		mlx->p.c_count++;
		flag++;
	}
	if (mlx->map.map[mlx->p.y - 1][mlx->p.x] == 'c')
	{
		mlx->map.map[mlx->p.y - 1][mlx->p.x] = 'C';
		mlx->p.c_count++;
		flag++;
	}
	if (mlx->map.map[mlx->p.y][mlx->p.x + 1] == 'c')
	{
		mlx->map.map[mlx->p.y][mlx->p.x + 1] = 'C';
		mlx->p.c_count++;
		flag++;
	}
	if (mlx->map.map[mlx->p.y][mlx->p.x - 1] == 'c')
	{
		mlx->map.map[mlx->p.y][mlx->p.x - 1] = 'C';
		mlx->p.c_count++;
		flag++;
	}
	ft_wait(0, 100);
	print_ilu(mlx, 'C');
	return (0);
}
int render_game(t_win *mlx)
{
	if (mlx->event == 1)
	{
		put_base_map(mlx);
		print_ilu(mlx, 'p');
		print_ilu(mlx, 'C');
		print_img(mlx, mlx->p.y, mlx->p.x, mlx->p.sprite);
		//event(mlx);
		mlx->event = 0;
		return (1);
	}
	else if (mlx->event == 2)
	{
		put_base_map(mlx);
		print_ilu(mlx, 'p');
		print_img(mlx, mlx->p.y, mlx->p.x, mlx->p.sprite);
		mlx->event = 0;
	}
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

