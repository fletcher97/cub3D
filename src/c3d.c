/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:26:36 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/18 20:35:47 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"

#include "ft_stdlib.h"
#include "ft_conv.h"
#include "ft_string.h"
#include "ft_err.h"

#include "c3d.h"
#include "c3d_error.h"
#include "c3d_map.h"
#include "c3d_listener.h"
#include "c3d_graphics.h"
#include "errors.h"

/*
 *	No need to initialize the player vars because of the use of calloc.
*/

void	init(t_cub3d *cub3d)
{
	t_screen	*s;
	t_img		*img;
	int			i;

	cub3d->mlx = mlx_init();
	get_screen(&cub3d->screen);
	s = &cub3d->screen;
	s->win = mlx_new_window(cub3d->mlx, s->width, s->height, s->title);
	s->img = ft_calloc(2, sizeof(t_img));
	if (!s->img)
		terminate(cub3d, FAILED_MALLOC);
	img = s->img;
	i = -1;
	while (++i < NB_IMGS)
	{
		img[i].img = mlx_new_image(cub3d->mlx, s->width, s->height);
		img[i].addr = mlx_get_data_addr(img[i].img, &img[i].bpp, &img[i].line,
				&img[i].endian);
	}
}

///still need to understand how you implemented this one
int	update(void *param)
{
	char		*frame;
	static int	frame_count = 0;
	t_cub3d		cub3d;

	cub3d = *((t_cub3d *) param);
	render(cub3d);
	next_frame(cub3d.screen, cub3d.mlx);
	frame_count++;
	frame = ft_itoa(frame_count);
	mlx_string_put(cub3d.mlx, cub3d.screen.win, cub3d.screen.width
		- (6 * ft_strlen(frame)), 10, 0x00000000, frame);
	ft_free(frame);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_cub3d	*cub3d;

	load_err("res/err.txt");
	if (argc != 2 || !ft_strendw(argv[1], ".cub"))
		terminate(NULL, ILLEGAL_INPUT);
	cub3d = ft_calloc(1, sizeof(t_cub3d));
	if (!cub3d)
		terminate(cub3d, FAILED_MALLOC);
	init(cub3d);
	load_map(cub3d, argv[1]);
	set_listeners(cub3d);
	mlx_loop_hook(cub3d->mlx, update, cub3d);
	mlx_loop(cub3d->mlx);
	terminate(cub3d, 0);
}
