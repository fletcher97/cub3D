/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 06:06:29 by mgueifao          #+#    #+#             */
/*   Updated: 2022/02/22 00:56:56 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GRAPHICS_H
# define C3D_GRAPHICS_H

#include "c3d.h"

# define NB_IMGS 2
# define FOV 1.570796
# define RENDER_STEP 1

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	get_screen(t_screen *screen);
void	next_frame(t_screen screen, void *mlx);
void	render(t_cub3d cub3d);
double	get_dist(double ang, t_game game, t_pos *pos);

#endif
