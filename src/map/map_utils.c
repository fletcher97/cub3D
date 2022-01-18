/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:20:17 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/14 00:29:03 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "errors.h"
#include "c3d_error.h"

/*
 *	According to the subject, there should be no empty lines on the map. Hence,
 *	if the status variable indicates that the program is already parsing the map
 *	and it has already read a non-empty line (which would set the cols to a
 *	non-zero value), then the map is invalid.
*/

int	handle_empty_line(t_cub3d *cub3d, char *line, int status)
{
	if (!line)
		return (FAILED_MALLOC);
	ft_free(line);
	if (status && cub3d->game.cols != 0)
		return (INVALID_MAP);
	else
		return (status);
}

/*
 *	Reads the first chars of the line to know what kind of element it will try
 *	to load. If the element is not valid, returns 0.
*/

int	is_valid_element(char *str, int *id)
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
	{
		*id = 0;
		return (0);
	}
	return (1);
}

/*
 *	Frees the temporary string array created by parse_header and load_colors.
*/

void	free_split(char **temp)
{
	int	iter;

	iter = -1;
	while (temp && temp[++iter])
		ft_free(temp[iter]);
	ft_free(temp);
	temp = NULL;
}

/*
 *	Makes sure every line on the map has the same length, by filling with space
 *	chars all the lines until reaching the length of the biggest one. This will
 *	make it easier to check the map's validity.
*/

void	fill_map_with_space_chars(t_cub3d *cub3d, t_game *game)
{
	int		row;
	int		len;
	char	*new_line;
	int		i;

	row = -1;
	while (++row < game->rows)
	{
		len = (int)ft_strlen(game->map[row]);
		if (game->cols - len)
		{
			new_line = ft_realloc(game->map[row], len + 1, game->cols + 1);
			if (new_line == game->map[row])
				terminate(cub3d, FAILED_MALLOC);
			i = len;
			while (i < game->cols)
				new_line[i++] = ' ';
			new_line[i] = '\0';
			game->map[row] = new_line;
		}
	}
}
