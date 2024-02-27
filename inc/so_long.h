/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:41:34 by frankgar          #+#    #+#             */
/*   Updated: 2024/02/26 10:41:58 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define WALL_LEFT_INDEX_SPRITE	0
# define WALL_RIGHT_INDEX_SPRITE 6
# define SPRITES_AMOUNT	13

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

typedef struct s_ca
{
	char	type;
	char	ilu;
	//t_data	img[3];
	t_data	*sprite;
}	t_cases;

typedef struct s_map
{
	t_cases	**map;
	t_data	sprites[SPRITES_AMOUNT];
	0 - 2 -> wall left
	3 - 5 -> floor
	6 - 8 -> wall right
	int		map_len;
	int		c_count;
	int		p_count;
	int		e_count;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		c_count;
	int		moves;
	char	stepping;
}	t_player;

int	ft_floodfill(t_map *map, t_player p);
int	parsing(int fd);
int	correct_file(char *pfile);

#endif
