/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:19:18 by mgueifao          #+#    #+#             */
/*   Updated: 2021/04/25 03:23:58 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_PLAYER_H
# define C3D_PLAYER_H

# include "c3d.h"

# define STEP	0.05

void	move_player(t_game *game);
void	move_camera(t_game *game);

#endif
