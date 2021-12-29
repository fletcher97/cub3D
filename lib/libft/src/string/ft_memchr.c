/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:04 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 19:22:44 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const t_uc	*p;
	size_t		i;

	p = (const t_uc *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == ((t_uc)c))
			return ((void *)&(p[i]));
		i++;
	}
	return (NULL);
}
