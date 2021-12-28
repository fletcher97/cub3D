/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:35:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 20:33:20 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_norm.h"

int	ft_strichr(const char *str, const char c)
{
	char	*pos;

	if (!ft_set64((int64_t *)&pos, (int64_t)ft_strchr(str, c)))
		return (-1);
	return (pos - str);
}
