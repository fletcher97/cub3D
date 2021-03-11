/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:21:57 by mgueifao          #+#    #+#             */
/*   Updated: 2021/03/09 02:07:07 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static void	render_ceil(t_cub3d cub3d, int color)
{
	int c = mlx_get_color_value(cub3d.mlx, color);
	for (int i = 0; i < cub3d.screen.height / 2; i++)
		for (int j = 0; j < cub3d.screen.width; j++)
			my_mlx_pixel_put(&cub3d.img[1], j, i, c);
}

static void	render_floor(t_cub3d cub3d, int color)
{
	int c;

	c = mlx_get_color_value(cub3d.mlx, color);
	for (int i = cub3d.screen.height / 2; i < cub3d.screen.height; i++)
		for (int j = 0; j < cub3d.screen.width; j++)
			my_mlx_pixel_put(&cub3d.img[1], j, i, c);
}

void render(t_cub3d cub3d)
{
	render_ceil(cub3d, 0x00ff0000);
	render_floor(cub3d, 0x0000ff00);
}
