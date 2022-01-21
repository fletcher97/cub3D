/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:59:00 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/19 21:18:22 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "c3d.h"

/*
	side=0; disV=100000;
  float Tan=tan(degToRad(ra));
       if(cos(degToRad(ra))> 0.001){ rx=(((int)px>>6)<<6)+64;      ry=(px-rx)*Tan+py; xo= 64; yo=-xo*Tan;}//looking left
  else if(cos(degToRad(ra))<-0.001){ rx=(((int)px>>6)<<6) -0.0001; ry=(px-rx)*Tan+py; xo=-64; yo=-xo*Tan;}//looking right
  else { rx=px; ry=py; dof=8;}                                                  //looking up or down. no hit

  while(dof<8)
  {
   mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
   if(mp>0 && mp<mapX*mapY && map[mp]==1){ dof=8; disV=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);}//hit
   else{ rx+=xo; ry+=yo; dof+=1;}                                               //check next horizontal
  }
  vx=rx; vy=ry;
*/

double dist(double x1, double y1, double x2, double y2)
{
	return (sqrt(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double	h_check(t_game g, double ang)
{
	t_pos	ray;
	t_pos	offset;

	if (g.player.dir < M_PI)
	{
		ray.y = ((int)g.player.pos.y);
		ray.x = (g.player.pos.y - ray.y) * (-1 / tan(ang)) + g.player.pos.x;
		offset.y = -1;
		offset.x = -offset.y * (-1 / tan(ang));
	}
	if (g.player.dir > M_PI)
	{
		ray.y = ((int)g.player.pos.y) + 1;
		ray.x = (g.player.pos.y - ray.y) * (-1 / tan(ang)) + g.player.pos.x;
		printf("RX:%lf\n", ray.x);
		offset.y = 1;
		offset.x = -offset.y * (-1 / tan(ang));
	}
	while (ray.y >= 0 && ray.y < g.rows && ray.x >= 0 && ray.x < g.cols)
	{
		if (g.map[(int)ray.y][(int)ray.x] != '1')
			return (dist(ray.x, ray.y, g.player.pos.x, g.player.pos.x));
		ray = (t_pos){ray.x + offset.x, ray.y + offset.y};
	}
	return (-1);
}

double	v_check(t_game g, double ang)
{
	t_pos	ray;
	t_pos	offset;

	if (g.player.dir > (M_PI / 2) && g.player.dir < (3 * M_PI / 2))
	{
		ray.x = ((int)g.player.pos.x) - 0.0001;
		ray.y = (g.player.pos.x - ray.x) * (-tan(ang)) + g.player.pos.x;
		offset.x = -1;
		offset.y = -offset.x * (-tan(ang));
	}
	if (g.player.dir < (M_PI / 2) || g.player.dir > (3 * M_PI / 2))
	{
		ray.y = ((int)g.player.pos.y) + 1;
		ray.x = (g.player.pos.y - ray.y) * (-tan(ang)) + g.player.pos.x;
		offset.y = 1;
		offset.x = -offset.y * (-tan(ang));
	}
	while (ray.y >= 0 && (int)ray.y < g.rows && ray.x >= 0 && (int)ray.x < g.cols)
	{
		if (g.map[(int)ray.y][(int)ray.x] != '1')
		{
			printf("hit %d %d. Dist: %lf %lf\n", (int)ray.x, (int)ray.y, g.player.pos.x, g.player.pos.x);
			return (dist(ray.x, ray.y, g.player.pos.x, g.player.pos.x));
		}
		ray.y += offset.y;
		ray.x += offset.x;
	}
	printf("out\n");
	return (-1);
}
