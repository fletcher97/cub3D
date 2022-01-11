/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:39:57 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/30 00:40:22 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "c3d_error.h"
#include "mlx.h"
#include "ft_stdlib.h"

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
// Find mac compatible alternative
//	if (cub3d->mlx)
//		mlx_destroy_display(cub3d->mlx);
	ft_free(cub3d->mlx);
	ft_free(cub3d);
	exit(exit_code);
}
