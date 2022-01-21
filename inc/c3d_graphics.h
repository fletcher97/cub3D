/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 06:06:29 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/19 00:46:36 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GRAPHICS_H
# define C3D_GRAPHICS_H

# define NB_IMGS 2
# define FOV 90.0

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	get_screen(t_screen *screen);
void	next_frame(t_screen screen, void *mlx);
void	render(t_cub3d cub3d);
double	get_dist(double ang, t_game game, t_pos *pos);
double	h_check(t_game g, double ang);
double	v_check(t_game g, double ang);

#endif
