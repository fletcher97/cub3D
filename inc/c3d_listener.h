/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_listener.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:04:23 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/27 19:32:02 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LISTENER_H
# define C3D_LISTENER_H

# define MLX_DESTROY_NOTIFY	17
# define MLX_FOCUS_LOST		10
# define MLX_KEY_PRESS		2
# define MLX_KEY_RELEASE	3

int		stop(void *param);
int		on_key_press(int key_code, void *param);
int		on_key_release(int key_code, void *param);
int		on_lost_focus(void *param);
void	set_listeners(t_cub3d *cub3d);

#endif //C3D_LISTENER_H
