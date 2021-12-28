/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:51:33 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/18 08:57:28 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_norm.h"
#include "ft_stdlib.h"

static char	*ultoa_rec_s(unsigned long l, int i, int *size)
{
	char	*ret;

	if (l == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(i + 1)))
			return (NULL);
		*size = i;
		ret[i] = '\0';
		return (ret);
	}
	if (!ft_set64((int64_t *)&ret, (int64_t)ultoa_rec_s(l / 10, i + 1, size)))
		return (NULL);
	ret[*size - i - 1] = ft_abs(l % 10) + '0';
	return (ret);
}

char	*ft_ultoa(unsigned long l)
{
	char	*ret;
	int		size;

	if (l == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(2)))
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	ret = ultoa_rec_s(l, 0, &size);
	return (ret);
}
