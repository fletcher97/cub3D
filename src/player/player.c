/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:25:30 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 19:57:15 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
//#include "player.h"
#include <float.h>

#include "c3d.h"

//t_player	*player_init(double x, double y, double dir)
//{
//	t_player	*player;
//
//	player = ft_malloc(sizeof(t_player));
//	player->pos.x = x;
//	player->pos.y = y;
//	player->dir = dir;
//	return (player);
//}
//
//void	player_destroy(t_player *player)
//{
//	ft_free(player);
//}



// double adjust(char )

//void	move_player(t_game *vars)
//{
//	double	x;
//	double	y;
//
//	x = vars->map.player_coord_x;
//	y = vars->map.player_coord_y;
//	if (vars->keys_flags.pressing_w || vars->keys_flags.pressing_s
//		|| vars->keys_flags.pressing_d || vars->keys_flags.pressing_a)
//	{
//		// Vertical mov
//		if (vars->keys_flags.pressing_w)
//			y -= STEP;
//		if (vars->keys_flags.pressing_s)
//			y += STEP;
//
//		// Vertical adjustment
//		if (vars->map.player_coord_y < y)
//		{
//			if (vars->map.matrix[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'
//				|| vars->map.matrix[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1')
//				y = ceil(y) - CENTER_OFFSET;
//		}
//		else if (vars->map.player_coord_y > y)
//		{
//			if (vars->map.matrix[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'
//				|| vars->map.matrix[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1')
//				y = ceil(y) - CENTER_OFFSET;
//		}
//
//		// HOrizontal mov
//		if (vars->keys_flags.pressing_d)
//			x += STEP;
//		if (vars->keys_flags.pressing_a)
//			x -= STEP;
//
//		// Horizontal adjustment
//
//		if (vars->map.player_coord_x < x)
//		{
//			if (vars->map.matrix[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1'){
//				x = ceil(x) - CENTER_OFFSET;
//			}
//			else if (vars->map.matrix[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x + CENTER_OFFSET - FLT_EPSILON)] == '1'){
//				x = ceil(x) - CENTER_OFFSET;
//			}
//		}
//
//		else if (vars->map.player_coord_x > x)
//		{
//			if (vars->map.matrix[(int) (y + CENTER_OFFSET - FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'){
//				x = ceil(x) - CENTER_OFFSET;
//			}
//			else if (vars->map.matrix[(int) (y - CENTER_OFFSET + FLT_EPSILON)][(int) (x - CENTER_OFFSET + FLT_EPSILON)] == '1'){
//				x = ceil(x) - CENTER_OFFSET;
//			}
//		}
//
//		change_player_position(&vars->map, y, x);
//	}
//}
//
//void	change_player_position(t_map *map, double new_y, double new_x)
//{
//	double	old_y;
//	double	old_x;
//
//	old_y = map->player_coord_y;
//	old_x = map->player_coord_x;
//	if ((int)new_y != (int)old_y || (int)new_x != (int)old_x)
//	{
//		map->matrix[(int) new_y][(int) new_x] = map->matrix[(int) old_y][(int) old_x];
//		map->matrix[(int) old_y][(int) old_x] = '0';
//	}
//	map->player_coord_y = new_y;
//	map->player_coord_x = new_x;
//}
