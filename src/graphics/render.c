/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:21:57 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/19 22:53:52 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "mlx.h"
#include "ft_stdlib.h"

#include "c3d.h"
#include "c3d_graphics.h"

// #define M_PI 33.0

static void	render_ceil(t_screen screen, int color, void *mlx, int a)
{
	int	i;
	int	j;
	int	col;
	(void)color;
	(void)mlx;
	// c = mlx_get_color_value(mlx, color);
	i = -1;

	int b, c, d;
	int step = 10;
	if (a < step * 1) {b = 0; c = 8; d = 16;}
	else if (a < step * 2) {b = 0; c = 8; d = 24;}
	else if (a < step * 3) {b = 0; c = 16; d = 8;}
	else if (a < step * 4) {b = 0; c = 16; d = 24;}
	else if (a < step * 5) {b = 0; c = 24; d = 8;}
	else if (a < step * 6) {b = 0; c = 24; d = 16;}
	else if (a < step * 7) {b = 8; c = 0; d = 16;}
	else if (a < step * 8) {b = 8; c = 0; d = 24;}
	else if (a < step * 9) {b = 8; c = 16; d = 0;}
	else if (a < step * 10) {b = 8; c = 16; d = 24;}
	else if (a < step * 11) {b = 8; c = 24; d = 0;}
	else if (a < step * 12) {b = 8; c = 24; d = 16;}
	else if (a < step * 13) {b = 16; c = 0; d = 8;}
	else if (a < step * 14) {b = 16; c = 0; d = 24;}
	else if (a < step * 15) {b = 16; c = 8; d = 0;}
	else if (a < step * 16) {b = 16; c = 8; d = 24;}
	else if (a < step * 17) {b = 16; c = 24; d = 0;}
	else if (a < step * 18) {b = 16; c = 24; d = 16;}
	else if (a < step * 19) {b = 24; c = 0; d = 8;}
	else if (a < step * 20) {b = 24; c = 0; d = 16;}
	else if (a < step * 21) {b = 24; c = 8; d = 0;}
	else if (a < step * 22) {b = 24; c = 8; d = 16;}
	else if (a < step * 23) {b = 24; c = 16; d = 0;}
	else {b = 24; c = 16; d = 8;}

	while (++i < screen.height / 2)
	{
		j = -1;
		while (++j < screen.width)
		{
			col = 0;
			col |= (j * 255 / 1366)<<b;
			col |= (i * 255 / 1366)<<c;
			col |= ((j+i) * 255 / (1366+768))<<d;
			my_mlx_pixel_put(&screen.img[1], j, i, col);
		}
	}
}

static void	render_floor(t_screen screen, int color, void *mlx, int a)
{
	int	i;
	int	j;
	int	col;
	(void)color;
	(void)mlx;
	// c = mlx_get_color_value(mlx, color);
	i = screen.height / 2 - 1;

	int b, c, d;
	int step = 10;
	if (a < step * 1) {b = 0; c = 8; d = 16;}
	else if (a < step * 2) {b = 0; c = 8; d = 24;}
	else if (a < step * 3) {b = 0; c = 16; d = 8;}
	else if (a < step * 4) {b = 0; c = 16; d = 24;}
	else if (a < step * 5) {b = 0; c = 24; d = 8;}
	else if (a < step * 6) {b = 0; c = 24; d = 16;}
	else if (a < step * 7) {b = 8; c = 0; d = 16;}
	else if (a < step * 8) {b = 8; c = 0; d = 24;}
	else if (a < step * 9) {b = 8; c = 16; d = 0;}
	else if (a < step * 10) {b = 8; c = 16; d = 24;}
	else if (a < step * 11) {b = 8; c = 24; d = 0;}
	else if (a < step * 12) {b = 8; c = 24; d = 16;}
	else if (a < step * 13) {b = 16; c = 0; d = 8;}
	else if (a < step * 14) {b = 16; c = 0; d = 24;}
	else if (a < step * 15) {b = 16; c = 8; d = 0;}
	else if (a < step * 16) {b = 16; c = 8; d = 24;}
	else if (a < step * 17) {b = 16; c = 24; d = 0;}
	else if (a < step * 18) {b = 16; c = 24; d = 16;}
	else if (a < step * 19) {b = 24; c = 0; d = 8;}
	else if (a < step * 20) {b = 24; c = 0; d = 16;}
	else if (a < step * 21) {b = 24; c = 8; d = 0;}
	else if (a < step * 22) {b = 24; c = 8; d = 16;}
	else if (a < step * 23) {b = 24; c = 16; d = 0;}
	else {b = 24; c = 16; d = 8;}

	while (++i < screen.height)
	{
		j = 0;
		while (++j < screen.width)
		{
			col = 0;
			col |= (j * 255 / 1366)<<b;
			col |= (i * 255 / 1366)<<c;
			col |= ((j+i) * 255 / (1366+768))<<d;
			my_mlx_pixel_put(&screen.img[1], j, i, col);
		}
	}
}

void	render_wall(void *mlx, t_game game, t_screen screen)
{
	// t_pos	pos;
	int		c;
	static int b = 0;

	for (int i = 0; i < screen.width-700; i++)
	{
		double ang = ((screen.width - i) * FOV / screen.width) - FOV / 2.0;
		ang = fmod(ang + game.player.dir + 360, 360) * (M_PI / 180);
		double h = h_check(game, ang);
		double v = v_check(game, ang);
		// double z = get_dist(((screen.width - i) * FOV / screen.width) - FOV / 2.0, game, &pos);
		// if (!z)
		// 	break ;
		double z;
		if (h < v || v == -1 || v == NAN || v == -NAN)
		{
			printf("%d horizontal\n", i);
			c = 0x66;
			z = h;
		}
		else
		{
			printf("%d vert\n", i);
			c = 0x22;
			z = v;
		}
		// double x = fabs(game.player.pos.x - pos.x);
		// double y = fabs(game.player.pos.y - pos.y);
		// printf("[%d] z: %lf\n", i, fabs(z));
		// z = sqrt(x*x+y*y);
		// printf("[%d] - z: %lf\n", i, fabs(z));
		// printf("[%d] - z: %lf\n", i, tan(FOV/2) * fabs(z) / 2);
		double vfovh = (tan(FOV / 2) * fabs(z))/2;
		double pcount = (screen.height / 4) / vfovh;
		printf("pcount %lf color: %d\n", pcount, c);
		int j = screen.height / 2 - pcount;
		if (j < 0)
			j = 0;
		for (; j < screen.height / 2 + pcount && j < screen.height; j++)
		{
			my_mlx_pixel_put(&screen.img[1], i, j, mlx_get_color_value(mlx, c));
		}
	}
	b = 1;
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

void	render(t_cub3d cub3d)
{
	static int a = 0;
	// static int b = 0;
	// static int c = 0;
	// static int d = 0;
	// if (b)
	// 	// while (1);
	// 	return;

	// test(cub3d);

	a = (a + 1)%120;

	render_ceil(cub3d.screen, 0x000000ff, cub3d.mlx, a);
	render_floor(cub3d.screen, 0x00bbff55, cub3d.mlx, a);
	// render_wall(cub3d.mlx, cub3d.game, cub3d.screen);
	// b = 1;
}
