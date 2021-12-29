/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 18:45:36 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_norm.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			inc;
	size_t		i;
	t_uc		*d;
	const t_uc	*s;

	if (!dest && !src)
		return (0);
	if (!n)
		return (dest);
	d = (t_uc *)dest;
	s = (const t_uc *)src;
	inc = ft_ternary16(dest < src, 1, -1);
	i = ft_ternary64(dest < src, 0, n - 1);
	n = ft_ternary64(dest < src, n, 0);
	while (i != n)
	{
		d[i] = s[i];
		i += inc;
	}
	if (!i)
		d[i] = s[i];
	return (dest);
}
