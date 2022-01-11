/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantos <jsantos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:08:27 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/11 18:59:16 by jsantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "c3d_player.h"

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_img;

typedef struct s_tex
{
	int **no;
	int **so;
	int **ea;
	int **we;
	int c;
	int f;
}				t_tex;

typedef struct s_screen
{
	void	*win;
	int		width;
	int		height;
	char	*title;
	t_img	*img;
	t_tex	textures;
}				t_screen;

typedef struct s_map
{
	char	**map;
}				t_map;

/*
 * x_mov, y_mov and cam_rot represent horizontal and vertical movement and
 * cam_rotation flags (-1, 0, 1)
*/

typedef struct s_player
{
	t_pos		pos;
	double		dir;
	int			x_mov;
	int			y_mov;
	int 		cam_rot;
}				t_player;

typedef struct s_game
{
	int			width; //unnecessary?
	int			height; //unnecessary?
	t_player	player;
	t_map		map;
}				t_game;

typedef struct s_cub3d
{
	void		*mlx;
	t_screen	screen;
	t_game		game;
}				t_cub3d;

#endif
