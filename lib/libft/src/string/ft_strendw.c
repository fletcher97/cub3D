/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:35:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/16 00:35:24 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strendw(const char *str, const char *end)
{
	t_uc	*s;
	t_uc	*d;

	if (!str)
		return (0);
	if (!end || !*end)
		return (1);
	if (ft_strlen(str) < ft_strlen(end))
		return (0);
	s = (t_uc *)ft_strchr(str, '\0');
	d = (t_uc *)ft_strchr(end, '\0');
	while (s > (t_uc *)str && d > (t_uc *)end && *s == *d)
	{
		s--;
		d--;
	}
	return (*s == *d);
}
