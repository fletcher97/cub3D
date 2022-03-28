/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:37:16 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/28 17:21:51 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MAP_H
# define C3D_MAP_H

# include "c3d.h"

/*
** MAP_PARSER_OUTPUT
 * Offset means the player center offset
*/

# define EMPTY_LINE					0
# define SUCCESSFUL_IMPORT			1
# define TEXTURE_SIZE				64
# define NULL_TERM					1
# define BITS_PER_BYTE				8
# define NUMBER_OF_CHANNELS			3
# define OFFSET						0.25

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

void	load_map(t_cub3d *cub3d, int file);
int		handle_empty_line(t_cub3d *cub3d, char *line, int status);
int		parse_header(void *mlx, t_tex *tex, char *line);
int		load_elements(void *mlx, t_tex *tex, char **aux, int id);
int		is_valid_element(char *str, int *id);
int		load_tex(void *mlx, int ***texture, char *path);
int		texture_init(int ***tex);
void	voidp_to_matrix(t_img tmp, int ***texture, int height, int width);
int		ft_strchr_all(char *str, char chr);
int		load_color(int *color, char *comma_sep_channels);
int		parse_map(t_cub3d *cub3d, t_game *game, char *line, int line_length);
void	fill_map_with_space_chars(t_cub3d *cub3d, t_game *game);
int		is_map_valid(t_game *game);
void	free_split(char **temp);

#endif
