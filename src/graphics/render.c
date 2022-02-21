/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:21:57 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/21 09:27:08 by fletcher         ###   ########.fr       */
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
#include "c3d_ray_cast.h"
#include "c3d_map.h"

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

void print_map(t_game game){
	for (int i = 0; i < game.rows; i++)
	{
		for (int j = 0; j < game.cols; j++)
			printf("%c", game.map[i][j]);
		printf("\n");
	}
}

void render_wall(void *mlx, t_game game, t_screen screen)
{
	int c;
	const int step = 1;
	(void)mlx;

	for (int i = 0; i < screen.width; i += step)
	{
		double ang = (i * FOV / screen.width) - FOV / 2.0;
		ang = fmod(game.player.dir + ang + (2 * M_PI), (2 * M_PI));
		t_check_ret hcheck = (t_check_ret){.x = 0, .y = 0, .z = 0};
		t_check_ret vcheck = (t_check_ret){.x = 0, .y = 0, .z = 0};
		t_check_ret check;
		h_check(game, ang, &hcheck, game.player.pos);
		v_check(game, ang, &vcheck, game.player.pos);
		t_pos tex = {.x = 0, .y = 0};
		int **texture;
		if ((hcheck.z < vcheck.z && hcheck.z > 0.0) || vcheck.z < 0)
		{
			check = hcheck;
			tex.x = (check.x - (int)check.x) * TEXTURE_SIZE;
			if (ang > M_PI)
				texture = screen.textures.so;
			else
			{
				tex.x = TEXTURE_SIZE - tex.x - 1;
				texture = screen.textures.no;
			}
		}
		else
		{
			check = vcheck;
			tex.x = (check.y - (int)check.y) * TEXTURE_SIZE;
			if (ang > M_PI_2 && ang < M_PI_2 * 3)
			{
				tex.x = TEXTURE_SIZE - tex.x - 1;
				texture = screen.textures.we;
			}
			else
				texture = screen.textures.ea;
		}
		check.z = check.z * cos(fmod(game.player.dir - ang + 2.0 * M_PI, 2 * M_PI));
		double lineH = (double)screen.height / check.z;
		double lineO = ((double)screen.height - lineH) / 2;
		double to = 0;
		if (lineO < 0)
			to = (lineH - screen.height) / 2.0;
		if (lineO < 0)
			lineO = 0;
		tex.y = to * (TEXTURE_SIZE / (double)lineH);
		for (int j = lineO; j < screen.height && j < lineH + lineO; j++)
		{

			c = texture[(int)tex.y][(int)(tex.x)];
			for (int k = 0; k < step; k++){
				my_mlx_pixel_put(&screen.img[1], screen.width - (i + k), j, c);
			}
			tex.y += TEXTURE_SIZE / (double)lineH;
			if ((int)tex.y == TEXTURE_SIZE)
				tex.y = TEXTURE_SIZE - 1;
		}
	}
}

void render(t_cub3d cub3d)
{
	static double a = 0.0;
	// static int b = 0;
	// if (b)
	// 	 while (1);
	// 	return;

	cub3d.game.player.dir += a;
	a += 0.05;

	render_ceil(cub3d.screen, cub3d.screen.textures.c);
	render_floor(cub3d.screen, cub3d.screen.textures.f);
	//render_ceil(cub3d.screen, 0x0075c6ff);
	//render_floor(cub3d.screen, 0x004d4d4d);
	render_wall(cub3d.mlx, cub3d.game, cub3d.screen);
	// b = 1;
}
