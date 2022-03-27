/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:25:30 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/14 00:22:56 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>

#include "c3d.h"
#include "c3d_map.h"
#include "c3d_player.h"

/*
 *	Moves the player if the movement keys (WASD) are being pressed. It checks if
 *	moving the player the whole length of STEP makes it go past the map wall
 *	and, if so, it prevents it from going through the wall.
*/

void	move_player(t_game *game)
{
	double	x;
	double	y;
	int		temp_x;
	int		temp_y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	if (game->player.x_mov)
	{
		x += STEP * game->player.x_mov;
		temp_x = (int) (x + game->player.x_mov * (CENTER_OFFSET - FLT_EPSILON));
		if (game->map[(int) (y - CENTER_OFFSET + FLT_EPSILON)][temp_x] == '1'
			|| game->map[(int) (y + CENTER_OFFSET + FLT_EPSILON)][temp_x] == '1')
			x = ceil(x) - CENTER_OFFSET;
	}
	if (game->player.y_mov)
	{
		y += STEP * game->player.y_mov;
		temp_y = (int) (y + game->player.y_mov * (CENTER_OFFSET - FLT_EPSILON));
		if (game->map[temp_y][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'
			|| game->map[temp_y][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1')
			y = ceil(y) - CENTER_OFFSET;
	}
	game->player.pos.x = x;
	game->player.pos.y = y;
}

/*
 *	Moves the player if the movement keys (WASD) are being pressed. It checks if
 *	moving the player the whole length of STEP makes it go past the map wall
 *	and, if so, it prevents it from going through the wall.
*/

void	move_camera(t_game *game)
{
	double	dir;

	dir = game->player.dir;
	if (game->player.cam_rot)
		dir += STEP * game->player.cam_rot;
	if (dir > M_PI * 2)
		dir = 0;
	if (dir < 0)
		dir = M_PI * 2;
	game->player.dir = dir;
}
