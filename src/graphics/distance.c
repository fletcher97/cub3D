/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:24:54 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/15 18:34:58 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "c3d.h"

static int check(t_pos pos, t_game game)
{
	return (game.map.map[(int)pos.y][(int)pos.x]);
}

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
	double delta;

	*pos = (t_pos){ceil(game.player.pos.x), floor(game.player.pos.y)};
	while (pos->x < game.width)
	{
		delta = tan(ang) * (pos->x - game.player.pos.x);
		while (game.player.pos.y - delta < pos->y && pos->y > 0)
			if (check((t_pos){pos->x - 1, --pos->y}, game))
				return (((game.player.pos.y - pos->y + 1) / sin(ang)) * -1 );
		if (check((t_pos){pos->x++, pos->y}, game))
			return ((pos->x - 1 - game.player.pos.x) / cos(ang));
	}
	return (0);
}

static double	get_dist_2(double ang, t_game game, t_pos *pos)
{
	double delta;

	*pos = (t_pos){floor(game.player.pos.x), floor(game.player.pos.y)};
	while (pos->y > 0)
	{
		delta = tan(ang) * (game.player.pos.y - pos->y);
		while (game.player.pos.x - delta < pos->x && pos->x > 0)
			if (check((t_pos){--pos->x, pos->y}, game))
				return ((game.player.pos.x - pos->x + 1) / sin(ang));
		if (check((t_pos){pos->x, pos->y--}, game))
		{
			pos->y++;
			return (((game.player.pos.y - pos->y - 1) / cos(ang)) * -1);
		}
	}
	return (0);
}

static double	get_dist_3(double ang, t_game game, t_pos *pos)
{
	double delta;

	*pos = (t_pos){floor(game.player.pos.x), ceil(game.player.pos.y)};
	while (pos->x > 0)
	{
		delta = tan(ang) * (game.player.pos.x - pos->x);
		while (game.player.pos.y + delta < pos->y && pos->y < game.height)
			if (check((t_pos){pos->x, pos->y++}, game))
				return (((pos->y - 1 - game.player.pos.y) / sin(ang)) * -1);
		if (check((t_pos){--pos->x, pos->y - 1}, game))
			return ((game.player.pos.x - pos->x + 1) / cos(ang));
	}
	return (0);
}

static double	get_dist_4(double ang, t_game game, t_pos *pos)
{
	double delta;

	exit(0);
	*pos = (t_pos){ceil(game.player.pos.x), ceil(game.player.pos.y)};
	while (pos->y < game.height)
	{
		delta = tan(ang) * (pos->y - game.player.pos.y);
		while (game.player.pos.x + delta < pos->x && pos->x < game.width)
			if (check((t_pos){pos->x++, pos->y - 1}, game))
				return ((pos->x - 1 - game.player.pos.x) / sin(ang));
		if (check((t_pos){pos->x - 1, pos->y++}, game))
			return (((pos->y - 1 - game.player.pos.y) / cos(ang)) * -1);
	}
	return (0);
}

double	get_dist(double ang, t_game game, t_pos *pos)
{
	double	dist;

	// printf("%lf: ", ang);
	ang = fmod(ang + game.player.dir + 360, 360);
	// printf("%lf\n", ang);
	if (ang < 90)
	{
		// printf("90\n");
		dist = get_dist_1(ang * (M_PI/180), game, pos);
		pos->x--;
	}
	else if (ang < 180)
	{
		// printf("180\n");
		dist = get_dist_2((ang - 90) * (M_PI/180), game, pos);
	}
	else if (ang < 270)
	{
		// printf("270\n");
		dist = get_dist_3((ang - 180) * (M_PI/180), game, pos);
		pos->y--;
	}
	else
	{
		// printf("360\n");
		dist = get_dist_4((ang - 270) * (M_PI/180), game, pos);
		pos->x--;
		pos->y--;
	}
	// printf("\t%lf\n", dist);
	return (dist);
}
