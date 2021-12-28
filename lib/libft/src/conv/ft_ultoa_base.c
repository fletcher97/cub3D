/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:40:40 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/18 09:50:24 by mgueifao         ###   ########.fr       */
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

static char	*ultoa_base_rec_s(unsigned long n, int i, const char *base)
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
	ret = ultoa_base_rec_s(n / bsize, i + 1, base);
	if (ret == NULL)
		return (NULL);
	ret[i] = base[ft_abs(n % bsize)];
	return (ret);
}

char	*ft_ultoa_base(unsigned long n, const char *base)
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
	ret = ultoa_base_rec_s(n, 0, base);
	return (ft_strrev(ret));
}
