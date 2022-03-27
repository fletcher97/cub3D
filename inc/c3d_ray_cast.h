/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_ray_cast.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:45:16 by fletcher          #+#    #+#             */
/*   Updated: 2022/02/21 23:44:04 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_RAY_CAST_H
# define C3D_RAY_CAST_H

# include "c3d.h"

typedef struct s_check_ret
{
	double	x;
	double	y;
	double	z;
	t_pos	tex;
	int		**texture;
	double	lh;
	double	lo;
	double	texoff;
}				t_check_ret;

t_check_ret	*check_wall(t_game game, double ang, t_tex textures, t_screen s);

#endif // C3D_RAY_CAST_H
