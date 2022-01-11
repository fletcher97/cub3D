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
//#include ""

// static int	parse_map(int fd)
// {
// 	(void) fd;
// 	return (0);
// }

// int	load(const char *file)
// {
// 	int	fd;
// 	int	parse_status;

// 	if (!ft_strendw(file, ".cub"))
// 	{
// 		printf("[ERROR] : File name provided isn't a \'.cub\' map.");
// 		return (0);
// 	}
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("[ERROR] : %s\n", strerror(errno));
// 		return (0);
// 	}
// 	parse_status = parse_map(fd);
// 	close(fd);
// 	return (parse_status);
// }

static int  parse_map(char *line, t_cub3d *cub3d)
{
    (void) line;
    (void) cub3d;
    return (0);
}

int load_map(const char *file, t_cub3d *cub3d)
{
    int     fd;
    int     status;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        terminate(cub3d, 1);
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
