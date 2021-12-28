/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:30:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/03/11 03:49:09 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "c3d_map.h"
#include "ft_string.h"

static int	parse_map(int fd)
{
	(void) fd;
	return (0);
}

int	load(const char *file)
{
	int	fd;
	int	parse_status;

	if (!ft_strendw(file, ".cub"))
	{
		printf("[ERROR] : File name provided isn't a \'.cub\' map.");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("[ERROR] : %s\n", strerror(errno));
		return (0);
	}
	parse_status = parse_map(fd);
	close(fd);
	return (parse_status);
}
