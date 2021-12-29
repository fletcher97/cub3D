/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:40:23 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 19:11:57 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *dest, const char *src)
{
	t_uc	*d;
	size_t	s;

	d = (t_uc *)ft_strrchr(src, 0);
	s = 0;
	while (src[s])
	{
		*d = src[s];
		d++;
		s++;
	}
	*d = src[s];
	return (dest);
}
