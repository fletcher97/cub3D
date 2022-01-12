/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:29:33 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 02:18:44 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "ft_err.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"

static int	add_new_err(char *s)
{
	int	i;

	i = ft_strichr(s, ':');
	if (i == -1 || i == (int)ft_strlen(s))
		return (1);
	s[i] = 0;
	return (add_err(ft_atoi(s), &s[i + 1]));
}

/**
 * Load errors from a file. The files must be composed of one error per lineas
 * such: <error_code>:<error_msg>. If the file doesn't exists the function
 * fails. If the file is badly formatted the behaviour is unspecified.
 * @param path The path to the file containing errors to load
 * @return 1 if successful, 0 otherwise
*/
int	load_err(char *path)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (0);
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (i)
			i = add_new_err(line);
		ft_free(line);
	}
	if (i && line)
		i = add_new_err(line);
	if (line)
		ft_free(line);
	return (i);
}
