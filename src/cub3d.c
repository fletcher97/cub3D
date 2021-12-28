/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:26:36 by mgueifao          #+#    #+#             */
/*   Updated: 2021/04/25 07:22:35 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "mlx.h"

#include "ft_stdlib.h"
#include "ft_conv.h"
#include "ft_string.h"

#include "cub3d.h"
#include "c3d_map.h"
#include "c3d_keys.h"
#include "c3d_graphics.h"

char play = 1;

static int init(t_cub3d *cub3d)
{
	t_screen	*s;
	t_img		*img;

	cub3d->mlx = mlx_init();
	get_screen(&cub3d->screen);
	s = &cub3d->screen;
	s->win = mlx_new_window(cub3d->mlx, s->width, s->height, s->title);
	s->img = ft_malloc(2 * sizeof(t_img));
	if (!s->img)
		return (1);
	img = s->img;
	img[0].img = mlx_new_image(cub3d->mlx, s->width, s->height);
	img[0].addr = mlx_get_data_addr(img[0].img, &img[0].bpp, &img[0].line,
		&img[0].endian);
	img[1].img = mlx_new_image(cub3d->mlx, s->width, s->height);
	img[1].addr = mlx_get_data_addr(img[1].img, &img[1].bpp, &img[1].line,
		&img[1].endian);
	return (0);
}

void	terminate(t_cub3d cub3d)
{
	mlx_destroy_image(cub3d.mlx, cub3d.screen.img[1].img);
	mlx_destroy_image(cub3d.mlx, cub3d.screen.img[0].img);
	ft_free(cub3d.screen.img);
	mlx_destroy_window(cub3d.mlx, cub3d.screen.win);
	ft_free(cub3d.screen.title);
	mlx_destroy_display(cub3d.mlx);
	ft_free(cub3d.mlx);
}

int	stop(int key_code, void *param)
{
	t_cub3d cub3d;

	cub3d = *((t_cub3d *) param);
	if (key_code == C3D_KEY_ESC)
		terminate(cub3d);
	if (key_code == C3D_KEY_ESC)
		exit(0);
	printf("%d\n", key_code);
	return (0);
}

int update(void *param)
{
	char	*frame;
	static int frame_count = 0;
	t_cub3d cub3d;

	cub3d = *((t_cub3d *) param);
	render(cub3d);
	next_frame(cub3d.screen, cub3d.mlx);
	frame_count++;
	frame = ft_itoa(frame_count);
	mlx_string_put(cub3d.mlx, cub3d.screen.win, cub3d.screen.width - (6 * ft_strlen(frame)), 10, 0x00000000, frame);
	ft_free(frame);
	return 1;
}

int main()
{
	t_cub3d cub3d;

	if(init(&cub3d))
		return (1);

	mlx_key_hook(cub3d.screen.win, stop, &cub3d);
	mlx_loop_hook(cub3d.mlx, update, &cub3d);
	mlx_loop(cub3d.mlx);

	return 0;
}

// int main(int argc, char const *argv[])
// {
// 	if (argc < 2 || argc > 3)
// 		printf("Usage: ./cub3D <path-to-map> [--save]\n");
// 	if (argc < 2 || argc > 3)
// 		return (-1);
// 	//Map parsing
// 	if (!load(argv[1]))
// 		printf("error\n");
// 	else
// 		printf("success\n");
// 	return 0;
// }
