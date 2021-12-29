/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:12 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 18:45:27 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_uc		*d;
	const t_uc	*s;
	size_t		i;

	if (!src && !dest)
		return (NULL);
	d = (t_uc *)dest;
	s = (const t_uc *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
