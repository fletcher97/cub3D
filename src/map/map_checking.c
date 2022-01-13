#include "c3d_map.h"

static int	contains_only_allowed_chars(t_map *map);
static int	is_surrounded_by_walls(t_map *map);
static int	check_surroundings(t_map *map, int row, int column);
static int	save_player_position(t_map *map, int row, int column);

/*
**	Checks if the map is valid. A valid map must:
**	- contain only the following chars: 0 for an empty space, 1 for a wall, and
**	N,S,E or W for the player's starting position and orientation.
**	- be closed/surrounded by walls (1).
*/

int	is_map_valid(t_map *map)
{
	if (!contains_only_allowed_chars(map))
		return (0);
	if (!is_surrounded_by_walls(map))
		return (0);
	return (1);
}

/*
**	Checks if there's only one player starting position and orientation, and if
**	the rest of the map has only empty space ('0'), walls ('1') and ' ' that
**	fills the rest of the map outside of its shape.
*/

static int	contains_only_allowed_chars(t_map *map)
{
	int		start_position_counter;
	int 	row;
	int 	column;

	start_position_counter = 0;
	row = -1;
	while (++row < map->rows)
	{
		column = -1;
		while (map->matrix[row][++column] != '\0')
		{
			if (map->matrix[row][column] == 'N' || map->matrix[row][column] == 'S'
				|| map->matrix[row][column] == 'E' || map->matrix[row][column] == 'W')
				start_position_counter += save_player_position(map, row, column);
			else if (map->matrix[row][column] != ' '
					 && map->matrix[row][column] != '0'
					 && map->matrix[row][column] != '1')
				return (0);
		}
	}
	if (start_position_counter != 1)
		return (0);
	return (1);
}

/*
**	Checks if the map is surrounded by walls ('1'). It does so by looking for
**	every empty space char ('0') and the player position (NSEW) and checking:
**	1) whether they are located in the first/last row or the first/last column;
**	2) whether they are not surrounded by some char other than ' ' on the upper,
**	lower, right and left sides.
*/

static int	is_surrounded_by_walls(t_map *map)
{
	int		char_count;
	int 	row;
	int 	column;

	char_count = 0;
	row = -1;
	while (++row < map->rows)
	{
		column = -1;
		while (map->matrix[row][++column] != '\0')
		{
			if (map->matrix[row][column] == '0'
				|| map->matrix[row][column] == 'N'
				|| map->matrix[row][column] == 'S'
				|| map->matrix[row][column] == 'E'
				|| map->matrix[row][column] == 'W')
			{
				if (row == 0 || row == map->rows -1
					|| column == 0 || column == map->columns - 1)
					return (0);
				if (check_surroundings(map, row, column) == 0)
					return (0);
			}
		}
	}
	return (1);
}

static int	check_surroundings(t_map *map, int row, int column)
{
	if (map->matrix[row][column - 1] == ' '
		|| map->matrix[row][column + 1] == ' '
		|| map->matrix[row - 1][column] == ' '
		|| map->matrix[row + 1][column] == ' ')
		return (0);
	else
		return (1);
}


static int	save_player_position(t_map *map, int row, int column)
{
	map->player_coord_x = column + CENTER_OFFSET;
	map->player_coord_y = row + CENTER_OFFSET;
	map->player_orientation = map->matrix[row][column];
	return (1);
}
