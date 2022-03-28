/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:30:16 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/28 17:25:21 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "ft_math.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include "c3d_map.h"
#include "c3d_error.h"
#include "errors.h"
#include "ft_memutils.h"

/*
 *	Initializes and sets to NULL and 0 the variables used during the parsing of
 *	the .cub file. It also initializes the status variable, passed by address.
 */

void	init_parsing_variables(t_cub3d *cub3d, int *status)
{
	cub3d->screen.textures.no = NULL;
	cub3d->screen.textures.so = NULL;
	cub3d->screen.textures.ea = NULL;
	cub3d->screen.textures.we = NULL;
	cub3d->screen.textures.c = 0;
	cub3d->screen.textures.f = 0;
	cub3d->game.map = NULL;
	cub3d->game.cols = 0;
	cub3d->game.rows = 0;
	*status = 0;
}

/*
 *	Status can indicate error (-1), parsing header (0) or parsing map (1).
 *	Notice that in the end it calls fill_map_with_space_chars to end up with a
 *	rectangular map, so that the comparison between adjacent values does not
 *	segfault (that would happen if the lines on the matrix had different
 *	lengths).
 */

void	load_map(t_cub3d *cub3d, int fd)
{
	int		status;
	char	*line;
	size_t	line_length;

	if (fd == -1)
		terminate(cub3d, ERROR_READING_MAP_FILE);
	init_parsing_variables(cub3d, &status);
	while (get_next_line(fd, &line))
	{
		if (line != NULL)
			(line_length = ft_strlen(line));
		if (!line || !line_length)
			status = handle_empty_line(cub3d, line, status);
		else if (!status)
			status = parse_header(cub3d->mlx, &cub3d->screen.textures, line);
		else
			status = parse_map(cub3d, &cub3d->game, line, line_length);
		if (status < 0)
			terminate(cub3d, status);
	}
	ft_free(line);
	fill_map_with_space_chars(cub3d, &cub3d->game);
	if (!is_map_valid(&cub3d->game))
		terminate(cub3d, INVALID_MAP);
}

/*
 *	This function loads the passed on content to an element. It knows in which
 *	element to load thanks to the id parameter.
 */

int	load_elements(void *mlx, t_tex *tex, char **aux, int id)
{
	static char	ceil = 0;
	static char	floor = 0;
	int			ret;

	ret = 0;
	if (id == NO && !tex->no)
		ret = load_tex(mlx, &tex->no, aux[1]);
	else if (id == SO && !tex->so)
		ret = load_tex(mlx, &tex->so, aux[1]);
	else if (id == EA && !tex->ea)
		ret = load_tex(mlx, &tex->ea, aux[1]);
	else if (id == WE && !tex->we)
		ret = load_tex(mlx, &tex->we, aux[1]);
	else if (id == CEILING && !ceil && ++ceil)
		ret = load_color(&tex->c, aux[1]);
	else if (id == FLOOR && !floor && ++floor)
		ret = load_color(&tex->f, aux[1]);
	else
		return (REPEATED_ASSET);
	if (ceil > 1 || floor > 1)
		return (REPEATED_ASSET);
	if (ret < 0)
		return (ret);
	return (tex->no && tex->so && tex->ea && tex->we && ceil && floor);
}

/*
 *	Parses the map header to extract the path to the 4 textures and the value of
 *	the 2 colors.
 *	1) Starts by splitting the file line (passed as a parameter) using a space
 *	char (' ') as a separator. It then checks if there is information to load
 *	(either the path to the texture or the color value), and if there is no more
 *	(unwanted) information; the last string of the split should be null!
 *	2) Checks if the line is empty and, if not, which element it should load.
 *	3) Before loading the element, checks if that element has already been
 *	loaded; note that for checking whether the colors have been loaded, it would
 *	not be feasible to check whether it was different from 0. Hence, a static
 *	variable was created for each of them which works as a 'ret'.
 *
 *	This function's return value informs whether the map header has had an error
 *	(<0), it is still ongoing (0) or has finished and the program can start
 *	reading the map itself (1).
 */

int	parse_header(void *mlx, t_tex *tex, char *line)
{
	char		**aux;
	int			id;
	int			ret;

	aux = ft_split(line, ' ');
	ft_free(line);
	if (!aux)
		return (FAILED_MALLOC);
	if (!ft_strlen(aux[0]))
	{
		free_split(aux);
		return (0);
	}
	if (!aux[1] || aux[2] || !is_valid_element(aux[0], &id))
	{
		free_split(aux);
		return (ERROR_READING_MAP_FILE);
	}
	ret = load_elements(mlx, tex, aux, id);
	free_split(aux);
	return (ret);
}

/*
 *	Parses through the file and saves every read line to a reallocated matrix.
 *	Before doing so, it does check if the size of every line is the same, saving
 *	the biggest line length found so far.
 */

int	parse_map(t_cub3d *cub3d, t_game *game, char *line, int line_length)
{
	static size_t	i = 0;
	char			**new_matrix;

	if (line_length > game->cols)
		game->cols = line_length;
	new_matrix = ft_realloc(game->map, sizeof(char *) * i, sizeof(char *)
			* (i + 1));
	if (new_matrix == game->map)
		terminate(cub3d, FAILED_MALLOC);
	new_matrix[i++] = line;
	game->map = new_matrix;
	game->rows++;
	return (SUCCESSFUL_IMPORT);
}
