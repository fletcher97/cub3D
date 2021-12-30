/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_listner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:04:23 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/30 00:15:25 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LISTNER_H
# define C3D_LISTNER_H

# define MLX_DESTROY_NOTIFY	17
# define MLX_KEY_PRESS		2
# define MLX_KEY_RELEASE	3

int		stop(void *param);
int		on_key_press(int key_code, void *param);
int		on_key_release(int key_code, void *param);
void	set_listners(t_cub3d *cub3d);

#endif //C3D_LISTNER_H
