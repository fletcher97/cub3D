/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantos <jsantos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:37:16 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/11 18:15:30 by jsantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MAP_H
# define C3D_MAP_H

# include "c3d.h"

/*
** MAP_PARSER_OUTPUT
*/

# define EMPTY_LINE					0
# define SUCCESSFUL_IMPORT			1
# define TEXTURE_SIZE				32
# define NULL_TERM					1
# define BITS_IN_BYTE				8

/*
** ELEMENT TYPES ON THE MAP
*/

typedef enum e_graphics {
	NO		= 1,
	SO		= 2,
	WE		= 3,
	EA		= 4,
	CEILING	= 5,
	FLOOR	= 6,
}	t_graphics;

int		load_map(const char *file, t_cub3d *cub3d);
int		handle_empty_line(t_cub3d *cub3d, char *line, bool parsing_map);
int		parse_header(void *mlx, t_tex *textures, char *line, int flag);
int		check_element_id(char *str, int *id);
int		load_tex(void *mlx, int ***texture, char *path);
int		**voidp_to_matrix(t_img tmp, int height, int width);
int		**texture_init(void);
//recheck whether all of them are being used
void	free_split(char **temp);
int		is_ready_to_parse_map(int *loaded);
int		fill_map_with_space_chars(t_map *map);
void	free_parser_vars(t_game *vars, t_list *linked_list, char *line, int result);
int	load_mini_map_textures(t_game *vars);

#endif
