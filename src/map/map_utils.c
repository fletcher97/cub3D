#include "c3d_map.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "errors.h"

int	handle_empty_line(t_cub3d *cub3d, char *line, bool parsing_map)
{
	if (!line)
		return (FAILED_MALLOC);
	ft_free(line);
	if (parsing_map && cub3d->game.columns != 0)
		return (INVALID_MAP);
	else
		return (EMPTY_LINE);
}

/*
**	Reads the first chars of the line to know what kind of element it will try
**	to load.
*/

int	check_element_id(char *str, int *id)
{
	if (ft_strncmp(str, "NO", 3) == 0)
		*id = NO;
	else if (ft_strncmp(str, "SO", 3) == 0)
		*id = SO;
	else if (ft_strncmp(str, "WE", 3) == 0)
		*id = WE;
	else if (ft_strncmp(str, "EA", 3) == 0)
		*id = EA;
	else if (ft_strncmp(str, "C", 2) == 0)
		*id = CEILING;
	else if (ft_strncmp(str, "F", 2) == 0)
		*id = FLOOR;
	else
		*id = 0;
	return (0);
}

/*
 *	Frees the temporary string array created by parse_header and load_colors.
*/

void	free_split(char **temp)
{
	int iter;

	iter = -1;
	while (temp && temp[++iter])
		ft_free(temp[iter]);
	ft_free(temp);
	temp = NULL;
}



int	fill_map_with_space_chars(t_map *map)
{
	int 	row;
	int 	difference;

	row = -1;
	while (++row < map->rows)
	{
		difference = map->columns - ft_strlen(map->matrix[row]);
		if (difference)
			map->matrix[row] = ft_add_chars(map->matrix[row], ' ', difference);
		if (!map->matrix[row])
			return (0);
	}
	return (1);
}

void	free_parser_vars(t_cub3d *cub3d, char *line, int result)
{
	free(line);
	free_vars_and_exit(result, cub3d);
}
