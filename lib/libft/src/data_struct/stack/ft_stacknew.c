/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:43:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/16 02:34:07 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stack.h"

t_stack	*ft_stacknew(void)
{
	t_stack	*ret;

	ret = ft_malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->size = 0;
	ret->top = NULL;
	return (ret);
}
