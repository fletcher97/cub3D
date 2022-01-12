/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantos <jsantos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:30:16 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/11 18:40:14 by jsantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "ft_math.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include "c3d_map.h"
#include "c3d_error.h"
#include "errors.h"

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
	cub3d->game.columns = 0;
	cub3d->game.rows = 0;
}

int load_map(const char *file, t_cub3d *cub3d)
{
    int     fd;
    int     status;
    char    *line;
	size_t	line_length;
	int 		result;///these both could be replaced by the parsing_map
	bool		ready_to_parse_map;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        terminate(cub3d, 1);
    init_parsing_variables(cub3d);
	ready_to_parse_map = false;
	while (get_next_line(fd, &line))
	{
		line_length = ft_strlen(line);
		if (!line || line_length == 0)
			result = handle_empty_line(cub3d, line, ready_to_parse_map);
		else if (!ready_to_parse_map)
			result = parse_header(cub3d->mlx, &cub3d->screen.textures, line, 0);
		else
			result = parse_map(cub3d, line, line_length);
		if (result < 0)
			free_parser_vars(cub3d, linked_list, line, result);
	}
	if (!fill_map_with_space_chars(&cub3d->map))
		free_vars_and_exit(FAILED_MALLOC, cub3d);
	if (!is_map_valid(&cub3d->map))
		free_vars_and_exit(INVALID_MAP, cub3d);
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
**	Parses through the file and saves every read line to a new node on a linked
**	list. Before doing so, it does check if the size of every line is the same,
**	because the program requires a rectangular map.
*/

int	parse_map_to_list(t_game *vars, t_list **list, char *line, int line_length)
{
	t_list	*temp;

	if (line_length > vars->map.columns)
		vars->map.columns = line_length;
	temp = ft_lstnew(line);
	if (!temp)
		return (FAILED_MALLOC);
	ft_lstadd_back(list, temp);
	vars->map.rows++;
	return (SUCCESSFUL_IMPORT);
}

/*
**	Moves the lines' content to a matrix and frees the linked list.
*/

char	**list_to_matrix(t_game *vars, t_list *line_list, int lines)
{
	t_list	*temp;
	int		i;
	char	**matrix;

	matrix = malloc(sizeof(char *) * lines);
	if (!matrix)
	{
		free_list(line_list);
		free_vars_and_exit(FAILED_MALLOC, vars);
	}
	i = 0;
	while (i < lines)  ///for some reason, on lldb, lines are passed as a huge number (where are they set??),
/// and after i = 14, line_list is probably NULL, meaning that callint line_list->next will segfault
	{
		temp = line_list->next;
		matrix[i] = line_list->content;
		free(line_list);
		line_list = temp;
		i++;
	}
	return (matrix);
}
