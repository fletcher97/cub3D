/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:22:42 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 22:48:32 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"
#include "ft_norm.h"

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*dup;
	char	delim[2];
	int		cnt;
	int		pos;

	if (!s)
		return (NULL);
	delim[0] = c;
	delim[1] = '\0';
	cnt = ft_strwcnt(s, delim) + 1;
	if (!ft_set64((int64_t *)&ret, (int64_t)ft_malloc(sizeof(char *) * (cnt))))
		return (NULL);
	ret[--cnt] = NULL;
	if (!cnt)
		return (ret);
	dup = ft_strdup(s);
	pos = 0;
	ret[pos] = ft_strdup(ft_strtok(dup, delim));
	while (++pos < cnt)
		ret[pos] = ft_strdup(ft_strtok(NULL, delim));
	ft_free(dup);
	return (ret);
}
