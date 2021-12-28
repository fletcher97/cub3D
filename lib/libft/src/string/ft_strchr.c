/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 21:04:09 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_norm.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (t_uc)c)
		s++;
	return ((char *)
		ft_ternary64((int64_t) * s == (t_uc)c, (int64_t)s, (int64_t) NULL));
}
