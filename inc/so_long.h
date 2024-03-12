/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:41:34 by frankgar          #+#    #+#             */
/*   Updated: 2024/03/12 13:02:44 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define MAX_SPRITES 42
# define MANDATORI 1

# define E_ARGS "Error\nArguments.\n"
# define E_FILE "Error\nUnexpected File Extension.\n"
# define E_OPEN "Error\nNot Able To Open The File.\n"
# define E_CHARS "Error\nUnexpected Map Characters Found.\n"
# define E_NCLOSED "Error\nMap Not Closed.\n"
# define E_NGRIP "Error\nMap Doesn't Have a Grid Shape.\n"
# define E_CONTENT "Error\nAmount On The Map Content Is Not Right.\n"
# define E_IMPOSSIBLE "Error\nImpossible Map.\n"
# define E_MALLOC "Error\nMalloc's Fault.\n"

# define PJ_RIGHT 0
# define PJ_LEFT 1
# define PJ_UP 2
# define PJ_BACK 3
# define EXIT_C1 4
# define EXIT_C2 5
# define EXIT_O1 6
# define EXIT_O2 7
# define TORCH_O1 8
# define TORCH_C1 9
# define TORCH_C2 10
# define HOLE_1 11
# define HOLE_2 12
# define HOLE_3 13
# define HOLE_O 14
# define FLOOR_1 15
# define FLOOR_2 16
# define FLOOR_3 17
# define WALL_D1 18
# define WALL_D2 19
# define WALL_D3 20
# define WALL_DL1 21
# define WALL_DL2 22
# define WALL_DL3 23
# define WALL_DR1 24
# define WALL_DR2 25
# define WALL_DR3 26
# define WALL_L1 27
# define WALL_L2 28
# define WALL_L3 29
# define WALL_R1 30
# define WALL_R2 31
# define WALL_R3 32
# define WALL_U1 33
# define WALL_U2 34
# define WALL_U3 35
# define WALL_UL1 36
# define WALL_UL2 37
# define WALL_UL3 38
# define WALL_UR1 39
# define WALL_UR2 34
# define WALL_UR3 41

# define SPRITE_1 "./sprites/Character/Right.xpm" 
# define SPRITE_2 "./sprites/Character/Left.xpm"
# define SPRITE_3 "./sprites/Character/Front.xpm"
# define SPRITE_4 "./sprites/Character/Back.xpm"
# define SPRITE_5 "./sprites/Exit/Closed1.xpm"
# define SPRITE_6 "./sprites/Exit/Closed2.xpm"
# define SPRITE_7 "./sprites/Exit/Open1.xpm"
# define SPRITE_8 "./sprites/Exit/Open2.xpm"
# define SPRITE_9 "./sprites/Torch/Open1.xpm"
# define SPRITE_10 "./sprites/Torch/Closed1.xpm"
# define SPRITE_11 "./sprites/Torch/Closed2.xpm"
# define SPRITE_12 "./sprites/Hole/1.xpm"
# define SPRITE_13 "./sprites/Hole/2.xpm"
# define SPRITE_14 "./sprites/Hole/3.xpm"
# define SPRITE_15 "./sprites/Hole/Open1.xpm"
# define SPRITE_16 "./sprites/Floor/1.xpm"
# define SPRITE_17 "./sprites/Floor/2.xpm"
# define SPRITE_18 "./sprites/Floor/3.xpm"
# define SPRITE_19 "./sprites/Wall/Down/1.xpm"
# define SPRITE_20 "./sprites/Wall/Down/2.xpm"
# define SPRITE_21 "./sprites/Wall/Down/3.xpm"
# define SPRITE_22 "./sprites/Wall/DownLeft/1.xpm"
# define SPRITE_23 "./sprites/Wall/DownLeft/2.xpm"
# define SPRITE_24 "./sprites/Wall/DownLeft/3.xpm"
# define SPRITE_25 "./sprites/Wall/DownRight/1.xpm"
# define SPRITE_26 "./sprites/Wall/DownRight/2.xpm"
# define SPRITE_27 "./sprites/Wall/DownRight/3.xpm"
# define SPRITE_28 "./sprites/Wall/Left/1.xpm"
# define SPRITE_29 "./sprites/Wall/Left/2.xpm"
# define SPRITE_30 "./sprites/Wall/Left/3.xpm"
# define SPRITE_31 "./sprites/Wall/Right/1.xpm"
# define SPRITE_32 "./sprites/Wall/Right/2.xpm"
# define SPRITE_33 "./sprites/Wall/Right/3.xpm"
# define SPRITE_34 "./sprites/Wall/Up/1.xpm"
# define SPRITE_35 "./sprites/Wall/Up/2.xpm"
# define SPRITE_36 "./sprites/Wall/Up/3.xpm"
# define SPRITE_37 "./sprites/Wall/UpLeft/1.xpm"
# define SPRITE_38 "./sprites/Wall/UpLeft/2.xpm"
# define SPRITE_39 "./sprites/Wall/UpLeft/3.xpm"
# define SPRITE_40 "./sprites/Wall/UpRight/1.xpm"
# define SPRITE_41 "./sprites/Wall/UpRight/2.xpm"
# define SPRITE_42 "./sprites/Wall/UpRight/3.xpm"

typedef struct s_data
{
	void	*img;
	int		y;
	int		x;
}	t_data;

typedef struct s_map
{
	int		len;
	int		with;
	int		c_count;
	int		p_count;
	int		e_count;
	char	**map;
	t_data	*sprites;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		c_count;
	int		moves;
	int		sprite;
}	t_player;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	int			event;
	t_player	p;
	t_map		map;
}	t_win;

int		ft_floodfill(char **map, t_player p);
int		parsing(t_map *map, int fd, t_player *p);
int		correct_file(char *pfile);
int		add_map(t_map *map, char **tmp_map);
int		malloc_free_chars(char **tmp_map, int size);
char	*get_path(int n);
int		init_images(t_map *map, t_win *mlx);
int		movement(t_win *mlx, int y, int x);
int		print_img(t_win *mlx, int y, int x, int n);
int		put_base_map(t_win *mlx);
int		print_ilu(t_win *mlx, char c);
void    ft_wait(int i, int max);

#endif
