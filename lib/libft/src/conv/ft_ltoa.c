/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:16:25 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/18 08:49:14 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_norm.h"
#include "ft_stdlib.h"

static char	*ltoa_rec_s(long n, int i, int *s, int sign)
{
	char	*ret;

	if (n == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(i + 1)))
			return (NULL);
		*s = i - sign;
		ret[i] = '\0';
		return (ret);
	}
	ret = ltoa_rec_s(n / 10, i + 1, s, sign);
	if (ret == NULL)
		return (NULL);
	ret[(*s) - i] = ft_abs(n % 10) + '0';
	return (ret);
}

char	*ft_ltoa(long l)
{
	char	*ret;
	int		s;

	if (l == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(2)))
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	if (l < 0)
	{
		ret = ltoa_rec_s(l, 1, &s, 0);
		if (ret == NULL)
			return (NULL);
		ret[0] = '-';
	}
	else
		ret = ltoa_rec_s(l, 0, &s, 1);
	return (ret);
}
