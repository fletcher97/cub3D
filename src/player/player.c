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

/*
 *	Moves the player if the movement keys (WASD) are being pressed. It checks if
 *	moving the player the whole length of STEP makes it go past the map wall
 *	and, if so, it prevents it from going through the wall.
*/

void	move_player(t_game *game)
{
	double	x;
	double	y;

	x = game->player.pos.x;
	y = game->player.pos.y;
	// Vertical mov
	if (game->player.y_mov < 0) {
		x += STEP * -cos(game->player.dir); ///why do I need minus here??? is it because of the inverse of the x-axis?
		y += STEP * -sin(game->player.dir);
	} else {
		x += STEP * cos(game->player.dir); ///why do I need minus here??? is it because of the inverse of the x-axis?
		y += STEP * sin(game->player.dir);
	}

	//note that when going N, ymov is -1
	printf("ymov is %d\n", game->player.y_mov);


	// Vertical adjustment
	if (game->player.pos.y < y)
	{
		if (game->map[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'
			|| game->map[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1')
			y = ceil(y) - CENTER_OFFSET;
	}
	else if (game->player.pos.y > y)
	{
		if (game->map[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'
			|| game->map[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1')
			y = ceil(y) - CENTER_OFFSET;
	}

	// HOrizontal mov
//		x += STEP * game->player.x_mov;

	// Horizontal adjustment
	if (game->player.pos.x < x)
	{
		if (game->map[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1'){
			x = ceil(x) - CENTER_OFFSET;
		}
		else if (game->map[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1'){
			x = ceil(x) - CENTER_OFFSET;
		}
	}
	else if (game->player.pos.x > x)
	{
		if (game->map[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'){
			x = ceil(x) - CENTER_OFFSET;
		}
		else if (game->map[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'){
			x = ceil(x) - CENTER_OFFSET;
		}
	}
	// change_player_position(&game->map, y, x);
	game->player.pos.x = x;
	game->player.pos.y = y;
}
//void	move_player(t_game *game)
//{
//	double	x;
//	double	y;
//	int		temp_x;
//	int		temp_y;
//
//	x = game->player.pos.x;
//	y = game->player.pos.y;
//	if (game->player.x_mov)
//	{
//		x += STEP * game->player.x_mov;
////		x += STEP * game->player.x_mov * cos(game->player.dir * 180/M_PI);
////		y += STEP * game->player.y_mov * sin(game->player.dir * 180/M_PI);
////		printf("Degrees is %lf\n", game->player.dir * 180/M_PI);
//		printf("Pos is: %lf, %lf\n", game->player.pos.x, game->player.pos.y);
//		// x is a double, and hence cannot be used as an array subscript. So, we need to
//		//cast it to an int. But that alone won't do it, since it will allow the player to
//		//enter the walls.
//		temp_x = (int) (x + game->player.x_mov * (CENTER_OFFSET - FLT_EPSILON));
//		if (game->map[(int) (y - CENTER_OFFSET + FLT_EPSILON)][temp_x] == '1'
//			|| game->map[(int) (y + CENTER_OFFSET + FLT_EPSILON)][temp_x] == '1')
//			x = ceil(x) - CENTER_OFFSET;
//	}
//	if (game->player.y_mov)
//	{
//		y += STEP * game->player.y_mov;
//		temp_y = (int) (y + game->player.y_mov * (CENTER_OFFSET - FLT_EPSILON));
//		if (game->map[temp_y][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'
//			|| game->map[temp_y][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1')
//			y = ceil(y) - CENTER_OFFSET;
//	}
//	game->player.pos.x = x;
//	game->player.pos.y = y;
//}
/*
x += STEP * game->player.x_mov * cos(game->player.dir * 180/M_PI);
y += STEP * game->player.y_mov * sin(game->player.dir * 180/M_PI);
printf("Degrees is %lf\n", game->player.dir * 180/M_PI);
printf("Dir is %lf\n", game->player.dir);
*/


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
