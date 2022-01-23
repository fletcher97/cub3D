///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   player.c                                           :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2021/03/10 21:25:30 by mgueifao          #+#    #+#             */
///*   Updated: 2022/01/14 00:22:56 by mgueifao         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include <float.h>
//#include "ft_stdlib.h"
////#include "player.h"
//
//#include "c3d.h"
//#include "c3d_map.h"
//
//double	max_dist_within_step(t_game *game, double y)
//{
//
//}
//
//void	change_player_position(t_game *game, double new_y, double new_x)
//{
//	double	old_x;
//	double	old_y;
//
//	old_x = game->player.pos.x;
//	old_y = game->player.pos.y;
//	if ((int)new_y != (int)old_y || (int)new_x != (int)old_x)
//	{
//		game->map[(int) new_y][(int) new_x] = game->map[(int) old_y]
//		[(int) old_x];
//		game->map[(int) old_y][(int) old_x] = '0';
//	}
//	game->player.pos.x = new_x;
//	game->player.pos.y = new_y;
//}
//
//void	move_player(t_game *game)
//{
//	double	x;
//	double	y;
//
//	x = game->player.pos.x;
//	y = game->player.pos.y;
//	if (game->player.y_mov && game->map[(int)(y + CENTER_OFFSET - FLT_EPSILON)]
//	[(int)(x - CENTER_OFFSET + FLT_EPSILON)] != '1')
//	{
//		y = max_dist_within_step(game, y);// - CENTER_OFFSET;
//		change_player_position(game, y, x);
//	}
//	if (game->player.x_mov && game->map[(int)(y + CENTER_OFFSET - FLT_EPSILON)]
//							  [(int)(x - CENTER_OFFSET + FLT_EPSILON)] != '1')
//	{
//		x = max_dist_within_step(game, x);// - CENTER_OFFSET;
//		change_player_position(game, y, x);
//	}
//}
//
