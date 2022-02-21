/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_ray_cast.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:45:16 by fletcher          #+#    #+#             */
/*   Updated: 2022/02/21 06:59:26 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_RAY_CAST_H
# define C3D_RAY_CAST_H

#include "c3d.h"

typedef struct s_check_ret
{
	double x;
	double y;
	double z;
}				t_check_ret;

double	h_check(t_game g, double ang, t_check_ret *ray);
double	v_check(t_game g, double ang, t_check_ret *ray);

#endif // C3D_RAY_CAST_H
