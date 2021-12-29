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

#include "cub3d.h"

t_player	*player_init(double x, double y, double dir)
{
	t_player	*player;

	player = ft_malloc(sizeof(t_player));
	player->pos.x = x;
	player->pos.y = y;
	player->dir = dir;
	return (player);
}

void	player_destroy(t_player *player)
{
	ft_free(player);
}
