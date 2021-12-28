/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:34:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/18 09:50:40 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_norm.h"
#include "ft_stdlib.h"

static int	is_valid_base(const char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (--j >= 0)
			if (base[j] == base[i])
				return (0);
	}
	return (1);
}

static char	*ltoa_base_rec_s(long n, int i, int sign, const char *base)
{
	char	*ret;
	int		bsize;

	if (n == 0)
	{
		ret = ft_malloc(i + 1);
		if (ret == NULL)
			return (NULL);
		ret[i] = '\0';
		return (ret);
	}
	bsize = ft_strlen(base);
	ret = ltoa_base_rec_s(n / bsize, i + 1, sign, base);
	if (ret == NULL)
		return (NULL);
	ret[i] = base[ft_abs(n % bsize)];
	return (ret);
}

char	*ft_ltoa_base(long n, const char *base)
{
	char	*ret;

	if (!base || !*base || !is_valid_base(base))
		return (NULL);
	if (n == 0)
	{
		if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(2)))
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	if (n < 0)
	{
		ret = ltoa_base_rec_s(n, 1, 0, base);
		if (ret == NULL)
			return (NULL);
		ret[0] = '-';
		return (ft_strrev(ret + 1) - 1);
	}
	ret = ltoa_base_rec_s(n, 0, 1, base);
	return (ft_strrev(ret));
}
