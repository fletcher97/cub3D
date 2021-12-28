/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:32 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 21:13:12 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_norm.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r;

	r = (s + ft_strlen(s));
	while (r > s && (t_uc) * r != (t_uc)c)
		r--;
	return ((char *)ft_ternary64((t_uc) * r == (t_uc)c, (int64_t)r, 0));
}
