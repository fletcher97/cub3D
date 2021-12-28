/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:28 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/17 14:27:37 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	i;

	pos = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[pos] && pos + ft_strlen(little) <= len)
	{
		i = 0;
		while (big[pos + i] && little[i] && big[pos + i] == little[i])
			i++;
		if (!little[i] || big[pos + i] == little[i])
			return ((char *)(big + pos));
		pos++;
	}
	return (NULL);
}
