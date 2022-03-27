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
 *	These adjustments prevent the player from going through the walls. Notice
 *	that when making the first adjustment (in this case, for the y), it is
 *	crucial to use the current player->pos.x (and not the yet-to-be-x);
 *	otherwise, it will not work, it will get stuck when trying to move along a
 *	vertical wall.
 */

void	adjust_movement(t_player *player, char **map, double x, double y)
{
	double	off;

	off = OFFSET - FLT_EPSILON;
	if (y > player->pos.y
		&& (map[(int)(y + off)][(int)(player->pos.x - off)] == '1'
		|| map[(int)(y + off)][(int)(player->pos.x + off)] == '1'))
		y = ceil(y) - OFFSET;
	else if (y < player->pos.y
		&& (map[(int)(y - off)][(int)(player->pos.x - off)] == '1'
		|| map[(int)(y - off)][(int)(player->pos.x + off)] == '1'))
		y = floor(y) + OFFSET;
	if (x > player->pos.x
		&& (map[(int)(y + off)][(int)(x + off)] == '1'
		|| map[(int)(y - off)][(int)(x + off)] == '1'))
		x = ceil(x) - OFFSET;
	else if (x < player->pos.x
		&& (map[(int)(y + off)][(int)(x - off)] == '1'
		|| map[(int)(y - off)][(int)(x - off)] == '1'))
		x = floor(x) + OFFSET;
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
	int		vector_adj;
	double	angle_adj;
	double	x;
	double	y;

	vector_adj = -1;
	angle_adj = 1;
	if (player->x_mov == 0)
		vector_adj = player->y_mov;
	else if (player->y_mov == 0)
		angle_adj = M_PI_2;
	else if (player->y_mov > 0)
		angle_adj = M_PI_4 * 3;
	else
		angle_adj = M_PI_4;
	x = player->pos.x;
	x += vector_adj * STEP * cos(player->dir + player->x_mov * angle_adj);
	y = player->pos.y;
	y += vector_adj * STEP * sin(player->dir + player->x_mov * angle_adj);
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
