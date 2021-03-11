/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:55:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/03/09 01:23:12 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
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
	*(unsigned int*)dst = color;
}

void	next_frame(t_cub3d cub3d)
{
	// mlx_clear_window(cub3d.mlx, cub3d.screen.win);
	mlx_put_image_to_window(cub3d.mlx, cub3d.screen.win,
		cub3d.img[1].img, 0, 0);
	mlx_destroy_image(cub3d.mlx, cub3d.img[0].img);
	cub3d.img[0] = cub3d.img[1];
	cub3d.img[1].img =
		mlx_new_image(cub3d.mlx, cub3d.screen.width, cub3d.screen.height);
	cub3d.img[1].addr = mlx_get_data_addr(cub3d.img[1].img,
		&cub3d.img[1].bpp, &cub3d.img[1].line, &cub3d.img[1].endian);
}
