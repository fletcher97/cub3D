/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:35:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 19:10:55 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strendw(const char *str, const char *end)
{
	size_t	s;
	size_t	d;

	if (!str)
		return (0);
	if (!end || !*end)
		return (1);
	s = ft_strlen(str);
	d = ft_strlen(end);
	if (s < d)
		return (0);
	while (s > 0 && d > 0 && str[s] == end[d])
	{
		s--;
		d--;
	}
	return (str[s] == end[d]);
}
