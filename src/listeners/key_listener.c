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

#include "c3d.h"
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

/*
 *	This is called whenever a key is pressed. If the key is the 'Escape' key, it
 *	terminates the program. If it's either a move_player key (WSDA) or a
 *	move_camera key (left and right arrows), it sets the corresponding flag to
 *	1, so that the action will continue until the rey is released. This is
 *	possible because redraw_window is called in a loop.
*/

int	on_key_press(int key, void *param)
{
	t_cub3d	*cub3d;

	cub3d = ((t_cub3d *) param);
	if (key == C3D_KEY_ESC)
		terminate(cub3d, 0);
	if (key == C3D_KEY_W)
		cub3d->game.player.y_mov -= 1;
	else if (key == C3D_KEY_S)
		cub3d->game.player.y_mov += 1;
	else if (key == C3D_KEY_D)
		cub3d->game.player.x_mov += 1;
	else if (key == C3D_KEY_A)
		cub3d->game.player.x_mov -= 1;
	else if (key == C3D_KEY_LEFT_ARROW)
		cub3d->game.player.cam_rot -= 1;
	else if (key == C3D_KEY_RIGHT_ARROW)
		cub3d->game.player.cam_rot += 1;
	return (0);
}

/*
 *	This is called whenever a key is released. If the key is  a move_player key
 *	(WSDA) or a move_camera key (left and right arrows), it sets the
 *	corresponding flag to 0, therefore terminating the action.
*/

int	on_key_release(int key, void *param)
{
	t_cub3d	*cub3d;

	cub3d = ((t_cub3d *) param);
	if (key == C3D_KEY_ESC)
		terminate(cub3d, 0);
	if (key == C3D_KEY_W)
		cub3d->game.player.y_mov += 1;
	else if (key == C3D_KEY_S)
		cub3d->game.player.y_mov -= 1;
	else if (key == C3D_KEY_D)
		cub3d->game.player.x_mov -= 1;
	else if (key == C3D_KEY_A)
		cub3d->game.player.x_mov += 1;
	else if (key == C3D_KEY_LEFT_ARROW)
		cub3d->game.player.cam_rot += 1;
	else if (key == C3D_KEY_RIGHT_ARROW)
		cub3d->game.player.cam_rot -= 1;
	return (0);
}
