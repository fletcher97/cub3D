/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:39:57 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/18 23:33:06 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "ft_stdlib.h"

#include "c3d_error.h"
#include "c3d_map.h"

static void	free_map(t_cub3d *cub3d)
{
	int	i;

	while (cub3d->game.rows--)
		ft_free(cub3d->game.map[cub3d->game.rows]);
	ft_free(cub3d->game.map);
	i = TEXTURE_SIZE;
	while (i--)
	{
		ft_free(cub3d->screen.textures.no[i]);
		ft_free(cub3d->screen.textures.so[i]);
		ft_free(cub3d->screen.textures.ea[i]);
		ft_free(cub3d->screen.textures.we[i]);
	}
	ft_free(cub3d->screen.textures.no);
	ft_free(cub3d->screen.textures.so);
	ft_free(cub3d->screen.textures.ea);
	ft_free(cub3d->screen.textures.we);
}

// TODO: destroy map
// Find mac compatible alternative
//	if (cub3d->mlx)
//		mlx_destroy_display(cub3d->mlx);

void	terminate(t_cub3d *cub3d, int exit_code)
{
	if (!cub3d)
		exit(exit_code);
	if (cub3d->screen.img && cub3d->screen.img[1].img)
		mlx_destroy_image(cub3d->mlx, cub3d->screen.img[1].img);
	if (cub3d->screen.img && cub3d->screen.img[0].img)
		mlx_destroy_image(cub3d->mlx, cub3d->screen.img[0].img);
	ft_free(cub3d->screen.img);
	if (cub3d->mlx && cub3d->screen.win)
		mlx_destroy_window(cub3d->mlx, cub3d->screen.win);
	ft_free(cub3d->screen.title);
	free_map(cub3d);
	ft_free(cub3d->mlx);
	ft_free(cub3d);
	exit(exit_code);
}

/*
 * ILLEGAL_INPUT message:
 * printf("Cub3d must be run with the name of a single map file having the"
 * " extention \".cub\"\n");
*/
