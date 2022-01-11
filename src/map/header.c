/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantos <jsantos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:06:39 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/11 18:13:46 by jsantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "ft_string.h"

static int	load_img(int ***img, const char *path)
{
	(void) img;
	(void) path;
	return (0);
}

static int	get_color(int *col, const char *aux)
{
	(void) col;
	(void) aux;
	return (0);
}


int	parse_map_header(char *line, t_tex *textures)
{
	char	**aux;
	int		flag;

	aux = ft_split(line, ' ');
	if (!aux)
		return (-1);
	if (!ft_strlen(aux[0]))
		return (0);
	flag = 0;
	if (ft_strcmp(aux[0], "NO") && !textures->NO && aux[1] && !aux[2])
		flag = load_img(&textures->NO, aux[1]);
	else if (ft_strcmp(aux[0], "SO") && !textures->SO && aux[1] && !aux[2])
		flag = load_img(&textures->SO, aux[1]);
	else if (ft_strcmp(aux[0], "EA") && !textures->EA && aux[1] && !aux[2])
		flag = load_img(&textures->EA, aux[1]);
	else if (ft_strcmp(aux[0], "WE") && !textures->WE && aux[1] && !aux[2])
		flag = load_img(&textures->WE, aux[1]);
	else if (ft_strcmp(aux[0], "C") && !textures->C)
		flag = get_color(&textures->C, aux[1]);
	else if (ft_strcmp(aux[0], "F") && !textures->F)
		flag = get_color(&textures->F, aux[1]);
	if (flag != 1)
		return (-1);
	return (textures->NO && textures->SO && textures->EA && textures->WE
		&& textures->C && textures->F);
}
