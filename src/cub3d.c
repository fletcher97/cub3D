/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:26:36 by mgueifao          #+#    #+#             */
/*   Updated: 2021/03/11 04:33:21 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "cub3d.h"
#include "c3d_map.h"

// static int init(t_cub3d *cub3d)
// {
// 	t_screen	*s;
// 	t_img		*img;

// 	cub3d->mlx = mlx_init();

// 	get_screen(&cub3d->screen);
// 	s = &cub3d->screen;
// 	s->win = mlx_new_window(cub3d->mlx, s->width, s->height, s->title);

// 	cub3d->img = ft_malloc(2 * sizeof(t_img));
// 	if (!cub3d->img)
// 		return (1);
// 	img = cub3d->img;

// 	img[0].img = mlx_new_image(cub3d->mlx, s->width, s->height);
// 	img[0].addr = mlx_get_data_addr(img[0].img, &img[0].bpp, &img[0].line, &img[0].endian);
// 	img[1].img = mlx_new_image(cub3d->mlx, s->width, s->height);
// 	img[1].addr = mlx_get_data_addr(img[1].img, &img[1].bpp, &img[1].line, &img[1].endian);
// 	return (0);
// }

// void	debug(t_cub3d cub3d)
// {
// 	printf("cub3d{\n\tmlx: %p\n\timg: %p\n}\n", cub3d.mlx, cub3d.img);
// 	printf("screen{\n\twin: %p\n\twidth: %d\n\theight: %d\n\ttitle: %s\n}\n",
// 		cub3d.screen.win, cub3d.screen.width, cub3d.screen.height, cub3d.screen.title);
// 	printf("img%d{\n\timg: %p\n\taddr: %p\n\tbpp: %d\n\tline: %d\n\tendian: %d\n}\n",
// 		0, cub3d.img[0].img, cub3d.img[0].addr, cub3d.img[0].bpp, cub3d.img[0].line, cub3d.img[0].endian);
// 	printf("img%d{\n\timg: %p\n\taddr: %p\n\tbpp: %d\n\tline: %d\n\tendian: %d\n}\n",
// 		1, cub3d.img[1].img, cub3d.img[1].addr, cub3d.img[1].bpp, cub3d.img[1].line, cub3d.img[1].endian);
// }

// void	terminate(t_cub3d cub3d)
// {
// 	mlx_destroy_image(cub3d.mlx, cub3d.img[1].img);
// 	mlx_destroy_image(cub3d.mlx, cub3d.img[0].img);
// 	ft_free(cub3d.img);
// 	mlx_destroy_window(cub3d.mlx, cub3d.screen.win);
// 	ft_free(cub3d.screen.title);
// 	mlx_destroy_display(cub3d.mlx);
// }



// void	update(t_cub3d cub3d, short init)
// {
// 	static struct timespec prev;
// 	struct timespec now;
// 	static int delta = 1;

// 	if (init)
// 		clock_gettime(CLOCK_REALTIME, &prev);
// 	clock_gettime(CLOCK_REALTIME, &now);
// 	while (timeelapsed(prev, now) > delta)
// 	{
// 		game_update(cub3d);
// 		add_time(&prev, delta);
// 	}
// }

// int main()
// {
// 	t_cub3d cub3d;
// 	// time_t prev, now;

// 	if(init(&cub3d))
// 		return (1);
// 	// debug(cub3d);
// 	char *frame = ft_itoa(0);
// 	double i = 0, j = 0;
// 	// time(&prev);
// 	// update(1);
// 	while (++j < 2000)
// 	{
// 		i++;
// 		// time(&now);
// 		// if (prev < now)
// 		// {
// 		// 	prev = now;
// 			ft_free(frame);
// 			frame = ft_itoa(i);
// 		// 	i = 0;
// 		// }
// 		i++;
// 		render(cub3d);
// 		next_frame(cub3d);
// 		mlx_string_put(cub3d.mlx, cub3d.screen.win, cub3d.screen.width - (6 * ft_strlen(frame)), 10, 0x00000000, frame);
// 		// update(0);
// 	}
// 	ft_free(frame);

// 	// mlx_loop(cub3d.mlx);
// 	terminate(cub3d);
// 	return 0;
// }

int main(int argc, char const *argv[])
{
	if (argc < 2 || argc > 3)
	{
		printf("Usage: ./cub3D <path-to-map> [--save]\n");
		return (-1);
	}
	load(argv[1]);
	return 0;
}
