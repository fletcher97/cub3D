/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:08 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 19:03:06 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_uc	*c1;
	const t_uc	*c2;
	size_t		i;

	if (!n)
		return (0);
	c1 = (const t_uc *)s1;
	c2 = (const t_uc *)s2;
	i = 0;
	while (i < n && c1[i] == c2[i])
		i++;
	if (i == n)
		i--;
	return (c1[i] - c2[i]);
}
