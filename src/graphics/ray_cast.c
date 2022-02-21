/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:59:00 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/21 07:39:49 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#undef __STRICT_ANSI__
#define __USE_XOPEN
#include <math.h>

#include "c3d.h"
#include "c3d_ray_cast.h"

double	dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	h_check(t_game g, double ang, t_check_ret *r, t_pos player)
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

double	v_check(t_game g, double ang, t_check_ret *r, t_pos player)
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
