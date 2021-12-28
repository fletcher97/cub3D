/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:08:27 by mgueifao          #+#    #+#             */
/*   Updated: 2021/04/29 14:59:57 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "c3d_player.h"

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;

typedef struct	s_vector
{
	t_pos pos1;
	t_pos pos2;
}				t_vector;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_img;

typedef struct s_screen
{
	void	*win;
	int		width;
	int		height;
	char	*title;
	t_img	*img;
}				t_screen;

typedef struct	s_map
{
	int	**map;
}				t_map;

typedef	struct	s_player
{
	t_pos		pos;
	double		dir;
	t_vector	mov;
}				t_player;

typedef struct	s_game
{
	int			width;
	int			height;
	t_player	player;
	t_map		map;
}				t_game;

typedef struct	s_cub3d
{
	void		*mlx;
	t_screen	screen;
	t_game		game;
}				t_cub3d;

#endif
