/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:35:00 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/18 08:54:08 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_norm.h"
#include "ft_stdlib.h"

static char	*uitoa_rec_s(unsigned int n, int i, int *size)
{
	char	*ret;

	if (n == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(i + 1)))
			return (NULL);
		*size = i;
		ret[i] = '\0';
		return (ret);
	}
	if (!ft_set64((int64_t *)&ret, (int64_t)uitoa_rec_s(n / 10, i + 1, size)))
		return (NULL);
	ret[*size - i - 1] = ft_abs(n % 10) + '0';
	return (ret);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ret;
	int		size;

	if (n == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(2)))
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	ret = uitoa_rec_s(n, 0, &size);
	return (ret);
}
