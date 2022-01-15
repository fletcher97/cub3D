/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:21:57 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/15 18:28:45 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

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

//static void	render_wall(t_player player, t_map map, t_screen screen)
//{
//	(void) player;
//	(void) map;
//	(void) screen;
//}

void	render(t_cub3d cub3d)
{
	// static int b = 0;
	// if (b)
	// 	// while (1);
	// 	return;

	render_ceil(cub3d.screen, 0x000000ff, cub3d.mlx);
	render_floor(cub3d.screen, 0x00bbff55, cub3d.mlx);
	render_wall(cub3d.game.player, cub3d.game.map, cub3d.screen);
	// b = 1;
}
