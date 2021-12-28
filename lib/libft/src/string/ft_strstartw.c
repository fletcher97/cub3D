/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:35:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/25 21:50:45 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strstartw(const char *str, const char *start)
{
	t_uc	*s;
	t_uc	*d;

	if (!str)
		return (0);
	if (!start || !*start)
		return (1);
	if (ft_strlen(str) < ft_strlen(start))
		return (0);
	s = (t_uc *)str;
	d = (t_uc *)start;
	while (s[1] && d[1] && *s == *d)
	{
		s++;
		d++;
	}
	return (*s == *d);
}
