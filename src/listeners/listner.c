/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:01:15 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/30 00:04:18 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "cub3d.h"
#include "c3d_listner.h"

void	set_listners(t_cub3d *cub3d)
{
	mlx_hook(cub3d->screen.win, MLX_DESTROY_NOTIFY, 1L, stop, &cub3d);
	mlx_hook(cub3d->screen.win, MLX_KEY_PRESS, (1L << 0), on_key_press, &cub3d);
	mlx_hook(cub3d->screen.win, MLX_KEY_RELEASE, (1L << 1),
		on_key_release, &cub3d);
}
