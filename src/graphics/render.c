/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:21:57 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/21 02:28:29 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#undef __STRICT_ANSI__
#define __USE_XOPEN
#include <math.h>
#include <stdio.h>

#include "mlx.h"
#include "ft_stdlib.h"

#include "c3d.h"
#include "c3d_graphics.h"

// #define M_PI 33.0

static void render_ceil(t_screen screen, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < screen.height / 2)
	{
		j = -1;
		while (++j < screen.width)
			my_mlx_pixel_put(&screen.img[1], j, i, color);
	}
}

static void render_floor(t_screen screen, int color)
{
	int i;
	int j;

	i = screen.height / 2 - 1;
	while (++i < screen.height)
	{
		j = 0;
		while (++j < screen.width)
			my_mlx_pixel_put(&screen.img[1], j, i, color);
	}
}

void render_wall(void *mlx, t_game game, t_screen screen)
{
	int c;

	for (int i = 0; i < screen.width; i++)
	{
		double ang = ((screen.width - i) * FOV / screen.width) - FOV / 2.0;
		ang = fmod(ang + game.player.dir + 360, 360) * (M_PI / 180);
		double h = h_check(game, ang);
		double v = v_check(game, ang);
		double z;
		if ((h < v && h > 0.0) || v < 0)
		{
			c = 0x66;
			z = h;
		}
		else
		{
			c = 0x22;
			z = v;
		}
		double ca = fmod(ang - (game.player.dir * (M_PI / 180)) + 2 * M_PI, 2 * M_PI);
		z = z * cos(ca);
		double lineH = 320 / z;
		double lineO = (screen.height - lineH) / 2;
		if (lineO < 0)
			lineO = 0;
		for (int j = lineO; j < screen.height && j < lineH; j++)
		{
			my_mlx_pixel_put(&screen.img[1], i, j, mlx_get_color_value(mlx, c));
		}
	}
}

void test(t_cub3d c)
{
	t_pos pos;
	// double dir = 46;
	// double z = get_dist(((c.screen.width - 0) * FOV / c.screen.width) - FOV / 2.0, c.game, &pos);
	double z = get_dist(-39.992679, c.game, &pos);
	printf("dist: %lf\n", z);
	printf("pos: %lf %lf\n", pos.x, pos.y);
	// exit(0);
}

void render(t_cub3d cub3d)
{
	static int a = 0;
	// static int b = 0;
	// static int c = 0;
	// static int d = 0;
	// if (b)
	// 	// while (1);
	// 	return;

	// test(cub3d);

	cub3d.game.player.dir += a;
	printf("%lf\n", cub3d.game.player.dir);
	a++;

	render_ceil(cub3d.screen, 0x0075c6ff);
	render_floor(cub3d.screen, 0x004d4d4d);
	render_wall(cub3d.mlx, cub3d.game, cub3d.screen);
	// b = 1;
}
