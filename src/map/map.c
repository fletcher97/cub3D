/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:30:16 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/13 23:44:19 by mgueifao         ###   ########.fr       */
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
**	Initializes and sets to NULL and 0 the variables used during the parsing of
**	the .cub file.
*/

void	init_parsing_variables(t_cub3d *cub3d)
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
}

/*
 *	Status can indicate error (-1), parsing header (0) or parsing map (1).
*/

void	load_map(t_cub3d *cub3d, const char *file)
{
    int     fd;
    int     status;
    char    *line;
	size_t	line_length;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        terminate(cub3d, ERROR_READING_MAP_FILE);
    init_parsing_variables(cub3d);
    status = 0;
	while (get_next_line(fd, &line))
	{
		line_length = ft_strlen(line); //TODO: protect again NULL pointer
		if (!line || !line_length)
		{
			status = handle_empty_line(cub3d, line, status);
			ft_free(line);
		}
		else if (!status)
		{
			status = parse_header(cub3d->mlx, &cub3d->screen.textures, line, 0);
			ft_free(line);
		}
		else
			status = parse_map(cub3d, &cub3d->game, line, line_length);
		if (status < 0)
			terminate(cub3d, status);
	}
	fill_map_with_space_chars(cub3d, &cub3d->game);
	if (!is_map_valid(&cub3d->game))
		terminate(cub3d, INVALID_MAP);
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
 *	not be feasible to check whether it was differente from 0. Hence, a static
 *	variable was created for each of them which works as a flag.
 *
 *	This functions return value informs whether the map header has had an error
 *	(-1), it is still ongoing (0) or has finished and the program can start
 *	reading the map itself (1).
*/
/// TO-DO: output error message in case of duplicate entries (it is given an error
/// return value, but the specific error that occurs is not known to the calling function
///TO-DO: free the split in the various instances
int parse_header(void *mlx, t_tex *tex, char *line, int flag)
{
	char        **aux;
	int			id;
	static char	ceil = 0;
	static char floor = 0;

	aux = ft_split(line, ' ');
	if (!aux || !aux[1] || aux[2])
		return (-1);
	if (!ft_strlen(aux[0]) || check_element_id(aux[0], &id))
		return (0);
	if (id == NO && !tex->no)
		flag = load_tex(mlx, &tex->no, aux[1]);
	else if (id == SO && !tex->so)
		flag = load_tex(mlx, &tex->so, aux[1]);
	else if (id == EA && !tex->ea)
		flag = load_tex(mlx, &tex->ea, aux[1]);
	else if (id == WE && !tex->we)
		flag = load_tex(mlx, &tex->we, aux[1]);
	else if (id == CEILING && !ceil && ++ceil)
		flag = load_color(&tex->c, aux[1]);
	else if (id == FLOOR && !floor && ++floor)
		flag = load_color(&tex->f, aux[1]);
	if (flag != 1)
		return (-1);
	return (tex->no && tex->so && tex->ea && tex->we && ceil && floor);
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
	new_matrix = ft_realloc(game->map, sizeof(char *) * i, sizeof(char *) * (i + 1));
	if (new_matrix == game->map)
		terminate(cub3d, FAILED_MALLOC);
	new_matrix[i++] = line;
	game->map = new_matrix;
	game->rows++;
	return (SUCCESSFUL_IMPORT);
}
