/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:55:16 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/19 22:38:32 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include "ft_string.h"

void	get_screen(t_screen *screen)
{
	screen->height = 768;
	screen->width = 1366;
	screen->title = ft_strdup("Cub3D");
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));

	dst[3] = color >> 24;
	dst[2] = color >> 16;
	dst[1] = color >> 8;
	dst[0] = color;
}

void	next_frame(t_screen screen, void *mlx)
{
	t_img	tmp;

	mlx_put_image_to_window(mlx, screen.win,
		screen.img[1].img, 0, 0);
	tmp = screen.img[0];
	screen.img[0] = screen.img[1];
	screen.img[1] = tmp;
}
