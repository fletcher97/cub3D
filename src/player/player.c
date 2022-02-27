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
#include <stdio.h>


void	adjust_movement(t_player *player, char **map, double x, double y)
{
	if (player->pos.y < y)
	{
		if (map[(int) (y + OFFSET - FLT_EPSILON)][(int) (x - OFFSET + FLT_EPSILON)] == '1'
			|| map[(int) (y + OFFSET - FLT_EPSILON)][(int) (x + OFFSET - FLT_EPSILON)] == '1')
			y = ceil(y) - OFFSET;
	}
	else if (player->pos.y > y)
	{
		if (map[(int) (y - OFFSET + FLT_EPSILON)][(int) (x - OFFSET + FLT_EPSILON)] == '1'
			|| map[(int) (y - OFFSET + FLT_EPSILON)][(int) (x + OFFSET - FLT_EPSILON)] == '1')
			y = ceil(y) - OFFSET;
	}

	// Horizontal adjustment
	if (player->pos.x < x)
	{
		if (map[(int) (y + OFFSET - FLT_EPSILON)][(int) (x + OFFSET - FLT_EPSILON)] == '1'){
			x = ceil(x) - OFFSET;
		}
		else if (map[(int) (y - OFFSET + FLT_EPSILON)][(int) (x + OFFSET - FLT_EPSILON)] == '1'){
			x = ceil(x) - OFFSET;
		}
	}
	else if (player->pos.x > x)
	{
		if (map[(int) (y + OFFSET - FLT_EPSILON)][(int) (x - OFFSET + FLT_EPSILON)] == '1'){
			x = ceil(x) - OFFSET;
		}
		else if (map[(int) (y - OFFSET + FLT_EPSILON)][(int) (x - OFFSET + FLT_EPSILON)] == '1'){
			x = ceil(x) - OFFSET;
		}
	}
	player->pos.x = x;
	player->pos.y = y;
}

/*
 *	Moves the player if the movement keys (WASD) are being pressed. It checks if
 *	moving the player the whole length of STEP makes it go past the map wall
 *	and, if so, it prevents it from going through the wall.
*/

void	move_player(t_player *player, char **map)
{
	int		vectorAdj;
	double	angleAdj;
	double	x;
	double	y;

	vectorAdj = -1;
	angleAdj = 1;
	if (player->x_mov == 0)
		vectorAdj = player->y_mov;
	else if (player->y_mov == 0)
		angleAdj = M_PI_2;
	else if (player->x_mov > 0 && player->y_mov > 0)
	{
		vectorAdj = 1;
		angleAdj = -M_PI_4;
	}
	else if (player->x_mov < 0 && player->y_mov > 0)
		angleAdj = M_PI_4 * 3;
	else // if (player->x_mov < 0 && player->y_mov != 0)
		angleAdj = M_PI_4;
	x = player->pos.x;
	x += vectorAdj * STEP * cos(player->dir + player->x_mov * angleAdj);
	y = player->pos.y;
	y += vectorAdj * STEP * sin(player->dir + player->x_mov * angleAdj);
	adjust_movement(player, map, x, y);
}




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
