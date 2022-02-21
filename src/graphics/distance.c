/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:24:54 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/18 23:32:42 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "c3d.h"

/**
 * @brief Get the distance if angle is between 0 and 90
 *
 * @param ang the angle
 * @param game the game obj
 * @param pos pointer to pos obj to store the colided cell
 * @return The distance between the player and the wall
 */
static double	get_dist_1(double ang, t_game game, t_pos *pos)
{
	double	delta;

	*pos = (t_pos){ceil(game.player.pos.x), floor(game.player.pos.y)};
	while (pos->x < game.cols)
	{
		delta = tan(ang) * (pos->x - game.player.pos.x);
		while (game.player.pos.y - delta < pos->y && pos->y > 0)
			if (game.map[(int)--pos->y][(int)pos->x - 1] == '1')
				return (((game.player.pos.y - pos->y + 1) / sin(ang)) * -1);
		if (game.map[(int)pos->y][(int)pos->x++] == '1')
			return ((pos->x - 1 - game.player.pos.x) / cos(ang));
	}
	return (0);
}

static double	get_dist_2(double ang, t_game game, t_pos *pos)
{
	double	delta;

	*pos = (t_pos){floor(game.player.pos.x), floor(game.player.pos.y)};
	while (pos->y > 0)
	{
		delta = tan(ang) * (game.player.pos.y - pos->y);
		while (game.player.pos.x - delta < pos->x && pos->x > 0)
			if (game.map[(int)pos->y][(int)--pos->x] == '1')
				return ((game.player.pos.x - pos->x + 1) / sin(ang));
		if (game.map[(int)pos->y--][(int)pos->x] == '1')
		{
			pos->y++;
			return (((game.player.pos.y - pos->y - 1) / cos(ang)) * -1);
		}
	}
	return (0);
}

static double	get_dist_3(double ang, t_game game, t_pos *pos)
{
	double	delta;

	*pos = (t_pos){floor(game.player.pos.x), ceil(game.player.pos.y)};
	while (pos->x > 0)
	{
		delta = tan(ang) * (game.player.pos.x - pos->x);
		while (game.player.pos.y + delta < pos->y && pos->y < game.rows)
			if (game.map[(int)pos->y++][(int)pos->x] == '1')
				return (((pos->y - 1 - game.player.pos.y) / sin(ang)) * -1);
		if (game.map[(int)pos->y - 1][(int)--pos->x] == '1')
			return ((game.player.pos.x - pos->x + 1) / cos(ang));
	}
	return (0);
}

static double	get_dist_4(double ang, t_game game, t_pos *pos)
{
	double	delta;

	exit(0);
	*pos = (t_pos){ceil(game.player.pos.x), ceil(game.player.pos.y)};
	while (pos->y < game.rows)
	{
		delta = tan(ang) * (pos->y - game.player.pos.y);
		while (game.player.pos.x + delta < pos->x && pos->x < game.cols)
			if (game.map[(int)pos->y - 1][(int)pos->x++] == '1')
				return ((pos->x - 1 - game.player.pos.x) / sin(ang));
		if (game.map[(int)pos->y++][(int)pos->x - 1] == '1')
			return (((pos->y - 1 - game.player.pos.y) / cos(ang)) * -1);
	}
	return (0);
}

double	get_dist(double ang, t_game game, t_pos *pos)
{
	double	dist;

	ang = fmod(ang + game.player.dir + 360, 360);
	if (ang < 90)
	{
		dist = get_dist_1(ang * (M_PI / 180), game, pos);
		pos->x--;
	}
	else if (ang < 180)
		dist = get_dist_2((ang - 90) * (M_PI / 180), game, pos);
	else if (ang < 270)
	{
		dist = get_dist_3((ang - 180) * (M_PI / 180), game, pos);
		pos->y--;
	}
	else
	{
		dist = get_dist_4((ang - 270) * (M_PI / 180), game, pos);
		pos->x--;
		pos->y--;
	}
	return (dist);
}
