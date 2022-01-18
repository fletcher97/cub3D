/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:21:57 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/18 20:57:00 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "mlx.h"
#include "ft_stdlib.h"

#include "c3d.h"
#include "c3d_graphics.h"

static void	render_ceil(t_screen screen, int color, void *mlx)
{
	int	i;
	int	j;
	int	c;

	c = mlx_get_color_value(mlx, color);
	i = -1;
	while (++i < screen.height / 2)
	{
		j = -1;
		while (++j < screen.width)
			my_mlx_pixel_put(&screen.img[1], j, i, c);
	}
}

static void	render_floor(t_screen screen, int color, void *mlx)
{
	int	i;
	int	j;
	int	c;

	c = mlx_get_color_value(mlx, color);
	i = screen.height / 2 - 1;
	while (++i < screen.height)
	{
		j = 0;
		while (++j < screen.width)
			my_mlx_pixel_put(&screen.img[1], j, i, c);
	}
}

static void	render_wall(void *mlx, t_game game, t_screen screen)
{
	t_pos	pos;
	int		c;
	static int b = 0;

	for (int i = 0; i < screen.width; i++)
	{
		double z = get_dist(((screen.width - i) * FOV / screen.width) - FOV / 2.0, game, &pos);
		if (!z)
			break ;
		if (z < 0)
			c = 0x66;
		else
			c = 0x22;
		// double x = fabs(game.player.pos.x - pos.x);
		// double y = fabs(game.player.pos.y - pos.y);
		// printf("[%d] z: %lf\n", i, fabs(z));
		// z = sqrt(x*x+y*y);
		// printf("[%d] - z: %lf\n", i, fabs(z));
		// printf("[%d] - z: %lf\n", i, tan(FOV/2) * fabs(z) / 2);
		double vfovh = (tan(FOV / 2) * fabs(z)) / 2;
		double pcount = (screen.height / 4) / vfovh;
		// printf("pcount %lf color: %d\n", pcount, c);
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
	// static int b = 0;
	// if (b)
	// 	// while (1);
	// 	return;

	// test(cub3d);

	render_ceil(cub3d.screen, 0x000000ff, cub3d.mlx);
	render_floor(cub3d.screen, 0x00bbff55, cub3d.mlx);
	render_wall(cub3d.mlx, cub3d.game, cub3d.screen);
	// b = 1;
}
