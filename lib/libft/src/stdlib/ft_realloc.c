/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:50:14 by fletcher          #+#    #+#             */
/*   Updated: 2021/10/23 18:50:22 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

void	*ft_realloc(void *ptr, size_t osize, size_t nsize)
{
	char	*ret;

	if (!ptr)
		return (ft_malloc(nsize));
	if (!nsize)
		ft_free(ptr);
	if (!nsize)
		return (NULL);
	ret = ft_malloc(nsize);
	if (!ret)
		return (ptr);
	if (osize > nsize)
		osize = nsize;
	ft_memcpy(ret, ptr, osize);
	ft_free(ptr);
	return (ret);
}
