/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_general.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 06:06:29 by mgueifao          #+#    #+#             */
/*   Updated: 2021/04/25 03:23:23 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GRAPHICS_H
# define C3D_GRAPHICS_H

# define NB_IMGS 2

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	get_screen(t_screen *screen);
void	next_frame(t_screen screen, void *mlx);
void	render(t_cub3d cub3d);

#endif
