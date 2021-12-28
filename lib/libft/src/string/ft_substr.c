/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:23:39 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/19 18:39:27 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_norm.h"
#include "ft_stdlib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ret = ft_malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	size = ft_strlen(s + start);
	size = ft_ternary64(size > len, len, size);
	if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(size + 1)))
		return (NULL);
	ft_strncpy(ret, s + start, size);
	ret[size] = '\0';
	return (ret);
}
