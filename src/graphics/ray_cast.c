/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:59:00 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/21 20:18:19 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#undef __STRICT_ANSI__
#define __USE_XOPEN
#include <math.h>

#include "ft_stdlib.h"

#include "c3d.h"
#include "c3d_ray_cast.h"
#include "c3d_map.h"

static double	dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static double	h_check(t_game g, double ang, t_check_ret *r, t_pos player)
{
	t_pos	offset;

	if (ang > M_PI)
	{
		r->y = ((int)player.y) + 1.0001;
		r->x = (player.y - r->y) * (-1 / tan(ang)) + player.x;
		offset = (t_pos){.x = -1 * (-1 / tan(ang)), .y = 1};
	}
	if (ang < M_PI)
	{
		r->y = ((int)player.y) - 0.0001;
		r->x = (player.y - r->y) * (-1 / tan(ang)) + player.x;
		offset = (t_pos){.x = (-1 / tan(ang)), .y = -1};
	}
	if (ang != 0 && ang != M_PI)
	{
		while (r->y >= 0 && r->y < g.rows && r->x >= 0 && r->x < g.cols)
		{
			if (g.map[(int)r->y][(int)r->x] == '1')
				return (r->z = dist(r->x, r->y, player.x, player.y));
			(void) (t_pos){(r->x += offset.x), (r->y += offset.y)};
		}
	}
	return (r->z = -1);
}

static double	v_check(t_game g, double ang, t_check_ret *r, t_pos player)
{
	t_pos	offset;

	if (ang < M_PI_2 || ang > (3 * M_PI_2))
	{
		r->x = ((int)player.x) - 0.0001;
		r->y = (player.x - r->x) * (-tan(ang)) + player.y;
		offset = (t_pos){.x = -1, .y = -tan(ang)};
	}
	if (ang > M_PI_2 && ang < (3 * M_PI_2))
	{
		r->x = ((int)player.x) + 1.0001;
		r->y = (player.x - r->x) * (-tan(ang)) + player.y;
		offset = (t_pos){.x = 1, .y = tan(ang)};
	}
	if (ang != M_PI_2 && ang != M_PI_2 * 3)
	{
		while ((int)r->y >= 0 && (int)r->y < g.rows
			&& (int)r->x >= 0 && (int)r->x < g.cols)
		{
			if (g.map[(int)r->y][(int)r->x] == '1')
				return (r->z = dist(r->x, r->y, player.x, player.y));
			(void) (t_pos){r->x += offset.x, r->y += offset.y};
		}
	}
	return (r->z = -1);
}

static void	aux(double ang, t_check_ret *hvcheck, t_tex textures,
	t_check_ret *check)
{
	if ((hvcheck[0].z < hvcheck[1].z && hvcheck[0].z > 0.0) || hvcheck[1].z < 0)
	{
		*check = hvcheck[0];
		check->tex.x = (check->x - (int)check->x) * TEXTURE_SIZE;
		check->texture = textures.no;
		if (ang > M_PI)
			check->texture = textures.so;
		else
			check->tex.x = TEXTURE_SIZE - check->tex.x - 1;
	}
	else
	{
		*check = hvcheck[1];
		check->tex.x = (check->y - (int)check->y) * TEXTURE_SIZE;
		check->texture = textures.we;
		if (ang > M_PI_2 && ang < M_PI_2 * 3)
			check->tex.x = TEXTURE_SIZE - check->tex.x - 1;
		else
			check->texture = textures.ea;
	}
}

t_check_ret	*check_wall(t_game game, double ang, t_tex textures)
{
	t_check_ret	hvcheck[2];
	t_check_ret	*check;

	hvcheck[0] = (t_check_ret){.x = 0, .y = 0, .z = 0};
	hvcheck[1] = (t_check_ret){.x = 0, .y = 0, .z = 0};
	check = ft_calloc(1, sizeof(t_check_ret));
	h_check(game, ang, &hvcheck[0], game.player.pos);
	v_check(game, ang, &hvcheck[1], game.player.pos);
	aux(ang, hvcheck, textures, check);
	return (check);
}
