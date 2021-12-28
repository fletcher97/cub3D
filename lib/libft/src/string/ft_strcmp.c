/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:28:07 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/16 02:20:46 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!!s1 ^ !!s2)
		return (0);
	if (s1 == s2)
		return (1);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}
