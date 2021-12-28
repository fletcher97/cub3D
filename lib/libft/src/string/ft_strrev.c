/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:03:18 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 21:14:23 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"

char	*ft_strrev(char *str)
{
	int		i;
	char	*temp;

	if (!str)
		return (NULL);
	temp = str;
	i = ft_strlen(temp) - 1;
	while (i > 0)
	{
		ft_swap(temp, temp + i, 1);
		temp++;
		i -= 2;
	}
	return (str);
}
