/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantos <jsantos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:26:36 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/11 18:42:07 by jsantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "mlx.h"

#include "ft_stdlib.h"
#include "ft_conv.h"
#include "ft_string.h"

#include "cub3d.h"
#include "c3d_error.h"
#include "c3d_map.h"
#include "c3d_listener.h"
#include "c3d_graphics.h"

/*
 *	No need to initialize the player vars because of the use of calloc.
*/

static int	init(t_cub3d *cub3d)
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
		return (0);
	img = s->img;
	i = -1;
	while (++i < NB_IMGS)
	{
		img[i].img = mlx_new_image(cub3d->mlx, s->width, s->height);
		img[i].addr = mlx_get_data_addr(img[i].img, &img[i].bpp, &img[i].line,
										&img[i].endian);
	}
	return (1);
}

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

	if (argc != 2 || !ft_strendw(argv[1], ".cub"))
	{
		// to be dealt with error_handler
		printf("Cub3d must be run with the name of a single map file having the"
			" extention \".cub\"\n");
		return (1);
	}
	cub3d = ft_calloc(1, sizeof(t_cub3d));
	if (!cub3d)
		return (1);
	if (!init(cub3d))
		terminate(cub3d, 1);
	if (!load_map(argv[1], cub3d))
		terminate(cub3d, 1);
	set_listeners(cub3d);
	mlx_loop_hook(cub3d->mlx, update, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
