/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 07:24:09 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/30 00:32:39 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "c3d_keys.h"
#include <stdio.h>
#include "c3d_error.h"

int	stop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = ((t_cub3d *) param);
	terminate(cub3d, 0);
	return (0);
}

int	on_key_press(int key_code, void *param)
{
	t_cub3d	*cub3d;

	cub3d = ((t_cub3d *) param);
	if (key_code == C3D_KEY_ESC)
		terminate(cub3d, 0);
	printf("%d\n", key_code);
	return (1);
}

int	on_key_release(int key_code, void *param)
{
}
