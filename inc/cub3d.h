/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:08:27 by mgueifao          #+#    #+#             */
/*   Updated: 2021/03/09 00:23:07 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_screen
{
	void	*win;
	int		width;
	int		height;
	char	*title;
}				t_screen;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_img;

typedef struct	s_cub3d
{
	void		*mlx;
	t_screen	screen;
	t_img		*img;
}				t_cub3d;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	get_screen(t_screen *screen);
void	next_frame(t_cub3d cub3d);
void	render(t_cub3d cub3d);

void	render1(t_cub3d cub3d);
void	render2(t_cub3d cub3d);
void	render3(t_cub3d cub3d);
void	render4(t_cub3d cub3d);

#endif
