/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:00:10 by fletcher          #+#    #+#             */
/*   Updated: 2022/02/22 01:28:16 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_graphics.h"

void	draw_square(int x, int y, int color, t_screen s)
{
	int	k;
	int	l;

	k = -1;
	while (++k < MINIMAP_TILE_SIZE)
	{
		l = -1;
		while (++l < MINIMAP_TILE_SIZE)
			my_mlx_pixel_put(&s.img[1], s.width - x * MINIMAP_TILE_SIZE + k,
				y * MINIMAP_TILE_SIZE + l, color);
	}
}

void	render_map(t_game game, t_screen s)
{
	int	j;
	int	i;
	int	c;

	i = -1;
	while (++i < game.rows)
	{
		j = -1;
		while (++j <= game.cols)
		{
			c = 0;
			if (game.map[i][game.cols - j] == '1')
				c = 0xFFFFFF;
			draw_square(j, i, c, s);
		}
	}
	draw_square((game.cols - (int)game.player.pos.x),
		(int)game.player.pos.y, 0xFF0000, s);
}
