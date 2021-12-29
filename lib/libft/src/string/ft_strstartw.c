/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:35:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 18:40:43 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strstartw(const char *str, const char *start)
{
	size_t	s;
	size_t	d;

	if (!str)
		return (0);
	if (!start || !*start)
		return (1);
	if (ft_strlen(str) < ft_strlen(start))
		return (0);
	s = 0;
	d = 0;
	while (str[s] && start[d] && str[s] == start[d])
	{
		s++;
		d++;
	}
	return (str[s] == start[d]);
}
