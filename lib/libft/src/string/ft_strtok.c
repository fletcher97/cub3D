/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 04:30:32 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/17 14:26:38 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_norm.h"

char	*ft_strtok(char *str, const char *delim)
{
	char		*ret;
	static char	*curr = NULL;

	if ((!curr && !str) || !delim)
		return (NULL);
	curr = (char *)ft_ternary64((int64_t)str, (int64_t)str, (int64_t)curr);
	while (*curr && ft_strchr(delim, *curr))
		curr++;
	ret = curr;
	while (*curr && !ft_strchr(delim, *curr))
		curr++;
	if (*curr)
	{
		*curr = '\0';
		curr++;
	}
	curr = (char *)ft_ternary64((int64_t) * curr, (int64_t)curr, 0);
	return ((char *)ft_ternary64((int64_t) * ret, (int64_t)ret, 0));
}
