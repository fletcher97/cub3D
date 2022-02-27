/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:25:22 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/14 00:27:55 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define __USE_XOPEN
#include <math.h>
#include "c3d_map.h"

/*
 *	To avoid having to parse the map one extra time just to save the player
 *	initial position and orientation, the program saves that information when
 *	checking whether the map is valid.
*/

int	save_player_position(t_game *game, int row, int column)
{
	char	orientation;

	orientation = game->map[row][column];
	game->player.pos.x = column + OFFSET;
	game->player.pos.y = row + OFFSET;
	if (orientation == 'E')
		game->player.dir = 0.0;
	else if (orientation == 'N')
		game->player.dir = M_PI_2;
	else if (orientation == 'W')
		game->player.dir = M_PI;
	else if (orientation == 'S')
		game->player.dir = M_PI_2 * 3;
	return (1);
}

/*
 *	Checks if there's only one player starting position and orientation, and if
 *	the rest of the map has only empty space ('0'), walls ('1') and ' ' that
 *	fills the rest of the map outside of its shape.
*/

int	contains_only_allowed_chars(t_game *game)
{
	int		player;
	int		row;
	int		column;

	player = 0;
	row = -1;
	while (++row < game->rows)
	{
		column = -1;
		while (game->map[row][++column] != '\0')
		{
			if (game->map[row][column] == 'N' || game->map[row][column] == 'S'
				|| game->map[row][column] == 'E'
				|| game->map[row][column] == 'W')
				player += save_player_position(game, row, column);
			else if (game->map[row][column] != ' '
					&& game->map[row][column] != '0'
					&& game->map[row][column] != '1')
				return (0);
		}
	}
	if (player != 1)
		return (0);
	return (1);
}

int	check_surroundings(t_game *game, int row, int column)
{
	if (game->map[row][column - 1] == ' '
		|| game->map[row][column + 1] == ' '
		|| game->map[row - 1][column] == ' '
		|| game->map[row + 1][column] == ' ')
		return (0);
	else
		return (1);
}

/*
 *	Checks if the map is surrounded by walls ('1'). It does so by looking for
 *	every empty space char ('0') and the player position (NSEW) and checking:
 *	1) whether they are located in the first/last row or the first/last column;
 *	2) whether they are not surrounded by some char other than ' ' on the upper,
 *	lower, right and left sides.
*/

int	is_surrounded_by_walls(t_game *game)
{
	int		row;
	int		column;

	row = -1;
	while (++row < game->rows)
	{
		column = -1;
		while (game->map[row][++column] != '\0')
		{
			if (game->map[row][column] == '0'
				|| game->map[row][column] == 'N'
				|| game->map[row][column] == 'S'
				|| game->map[row][column] == 'E'
				|| game->map[row][column] == 'W')
			{
				if (row == 0 || row == game->rows -1
					|| column == 0 || column == game->cols - 1)
					return (0);
				if (check_surroundings(game, row, column) == 0)
					return (0);
			}
		}
	}
	return (1);
}

/*
 *	Checks if the map is valid. A valid map must:
 *	- contain only the following chars: 0 for an empty space, 1 for a wall, and
 *	N,S,E or W for the player's starting position and orientation.
 *	- be closed/surrounded by walls (1).
*/

int	is_map_valid(t_game *game)
{
	if (!contains_only_allowed_chars(game))
		return (0);
	if (!is_surrounded_by_walls(game))
		return (0);
	return (1);
}
