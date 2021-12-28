/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:58 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/14 00:37:52 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"

char	*ft_strsjoin(int size, char **strs, char *sep)
{
	size_t	total_size;
	char	*ret;
	int		i;
	int		pos;

	i = -1;
	total_size = 0;
	while (++i < size)
		total_size += ft_strlen(strs[i]);
	ret = ft_malloc(sizeof(char) * (
				total_size + ((size - 1) * ft_strlen(sep))));
	i = -1;
	pos = 0;
	while (++i < size)
	{
		ft_strcpy(&(ret[pos]), strs[i]);
		pos += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(&(ret[pos]), sep);
			pos += ft_strlen(sep);
		}
	}
	return (ret);
}
