/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:59:00 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/21 07:15:37 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#undef __STRICT_ANSI__
#define __USE_XOPEN
#include <math.h>
#include <stdio.h>

#include "c3d.h"
#include "c3d_ray_cast.h"

double dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	h_check(t_game g, double ang, t_check_ret *ray)
{
	t_pos	offset;

	if (ang > M_PI)
	{
		ray->y = ((int)g.player.pos.y) + 1.0001;
		ray->x = (g.player.pos.y - ray->y) * (-1 / tan(ang)) + g.player.pos.x;
		offset.y = 1;
		offset.x = -offset.y * (-1 / tan(ang));
	}
	if (ang < M_PI)
	{
		ray->y = ((int)g.player.pos.y) - 0.0001;
		ray->x = (g.player.pos.y - ray->y) * (-1 / tan(ang)) + g.player.pos.x;
		offset.y = -1;
		offset.x = -offset.y * (-1 / tan(ang));
	}
	if (ang != 0 && ang != M_PI)
		while (ray->y >= 0 && ray->y < g.rows && ray->x >= 0 && ray->x < g.cols)
		{
			printf("ang:%lf, ray %lf, %lf", ang, ray->x, ray->y);
			if (g.map[(int)ray->y][(int)ray->x] == '1')
				return (ray->z = dist(ray->x, ray->y, g.player.pos.x, g.player.pos.y));
			(ray->x += offset.x) && (ray->y += offset.y);
		}
	return (ray->z = -1);
}

double	v_check(t_game g, double ang, t_check_ret *r)
{
	t_pos	offset;

	if (ang < M_PI_2 || ang > (3 * M_PI_2))
	{
		r->x = ((int)g.player.pos.x) - 0.0001;
		r->y = (g.player.pos.x - r->x) * (-tan(ang)) + g.player.pos.y;
		offset.x = -1;
		offset.y = -offset.x * (-tan(ang));
	}
	if (ang > M_PI_2 && ang < (3 * M_PI_2))
	{
		r->x = ((int)g.player.pos.x) + 1.0001;
		r->y = (g.player.pos.x - r->x) * (-tan(ang)) + g.player.pos.y;
		offset.x = 1;
		offset.y = -offset.x * (-tan(ang));
	}
	if (ang != M_PI_2 && ang != M_PI_2 * 3)
		while ((int)r->y >= 0 && (int)r->y < g.rows && (int)r->x >= 0 && (int)r->x < g.cols)
		{
			printf("ang:%lf, ray %lf, %lf", ang, r->x, r->y);
			if (g.map[(int)r->y][(int)r->x] == '1')
				return (r->z = dist(r->x, r->y, g.player.pos.x, g.player.pos.y));
			(r->x += offset.x) && (r->y += offset.y);
		}
	return (r->z = -1);
}
