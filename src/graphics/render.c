/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:21:57 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/22 01:04:04 by fletcher         ###   ########.fr       */
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

static void	render_ceil(t_screen screen, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < screen.height / 2)
	{
		j = -1;
		while (++j < screen.width)
			my_mlx_pixel_put(&screen.img[1], j, i, color);
	}
}

static void	render_floor(t_screen screen, int color)
{
	int	i;
	int	j;

	i = screen.height / 2 - 1;
	while (++i < screen.height)
	{
		j = 0;
		while (++j < screen.width)
			my_mlx_pixel_put(&screen.img[1], j, i, color);
	}
}

void	render_wall(t_game game, t_screen screen)
{
	double		ang;
	t_check_ret	*check;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < screen.width)
	{
		ang = (i * FOV / screen.width) - FOV / 2.0;
		ang = fmod(game.player.dir + ang + (2 * M_PI), (2 * M_PI));
		check = check_wall(game, ang, screen.textures, screen);
		j = check->lo - 1;
		while (++j < screen.height && j < check->lh + check->lo)
		{
			k = -1;
			while (++k < RENDER_STEP)
				my_mlx_pixel_put(&screen.img[1], i + k, j,
					check->texture[(int)check->tex.y][(int)(check->tex.x)]);
			check->tex.y += TEXTURE_SIZE / (double)check->lh;
			(check->tex.y >= TEXTURE_SIZE) && (check->tex.y = TEXTURE_SIZE - 1);
		}
		ft_free(check);
		i += RENDER_STEP;
	}
}

void	render(t_cub3d cub3d)
{
	render_ceil(cub3d.screen, cub3d.screen.textures.c);
	render_floor(cub3d.screen, cub3d.screen.textures.f);
	render_wall(cub3d.game, cub3d.screen);
	render_map(cub3d.game, cub3d.screen);
}
