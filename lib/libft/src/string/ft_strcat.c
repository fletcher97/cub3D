/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:40:23 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/14 21:55:15 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *dest, const char *src)
{
	t_uc	*d;
	t_uc	*s;

	d = (t_uc *)ft_strrchr(src, 0);
	s = (t_uc *)src;
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = *s;
	return (dest);
}
