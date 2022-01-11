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
#include <stdio.h>

#include "c3d_map.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "c3d_error.h"

/*
**	Initializes and sets to NULL and 0 the variables used during the parsing of
**	the .cub file.
*/

void	init_parsing_variables(t_cub3d *cub3d, t_list **linked_list)
{
	cub3d->textures.no_texture = NULL;
	cub3d->textures.so_texture = NULL;
	cub3d->textures.ea_texture = NULL;
	cub3d->textures.we_texture = NULL;
	cub3d->ceiling_color = 0;
	cub3d->floor_color = 0;
	init_array(cub3d->loaded, NUM_OF_ELEMENTS_TO_LOAD);
	cub3d->game.map.matrix = NULL;
	cub3d->ready_to_parse_map = 0;
	*linked_list = NULL;
	cub3d->map.columns = 0;
	cub3d->map.rows = 0;
}

int load_map(const char *file, t_cub3d *cub3d)
{
    int     fd;
    int     status;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        terminate(cub3d, 1);

    //mine, yet to adapt; do not create a list, just realloc the strings and fill with chars
	init_parsing_variables(cub3d, &linked_list);
	while (get_next_line(fd, &line))
	{
		line_length = ft_strlen(line);
		if (!line || line_length == 0)
			result = handle_empty_line(cub3d, line);
		else if (cub3d->ready_to_parse_map == 0)
			result = parse_textures_and_colors(cub3d, line);
		else
			result = parse_map_to_list(cub3d, &linked_list, line, line_length);
		if (result < 0)
			free_parser_cub3d(cub3d, linked_list, line, result);
	}
	if (!linked_list)
		free_vars_and_exit(FAILED_MALLOC, vars);
	cub3d->map.matrix = list_to_matrix(cub3d, linked_list, cub3d->map.rows);
	if (!fill_map_with_space_chars(&cub3d->map))
		free_vars_and_exit(FAILED_MALLOC, cub3d);
	if (!is_map_valid(&cub3d->map))
		free_vars_and_exit(INVALID_MAP, cub3d);




   //from gueifao
    status = 0;
    while (get_next_line(fd, &line) > 0 && (!status || status == 1)){
        if (!status)
            status = parse_map_header(line, &cub3d->screen.textures);
        if (status == 1)
            status = parse_map(line, cub3d);
    }
    close(fd);
    return (status);
}
