/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 05:33:43 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 21:18:18 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strwcnt(const char *str, const char *delim)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	i = -1;
	while (str[++i])
	{
		if (!flag && !ft_strchr(delim, str[i]))
			flag = 1;
		else if (flag && ft_strchr(delim, str[i]))
		{
			flag = 0;
			count++;
		}
	}
	return (count + flag);
}
