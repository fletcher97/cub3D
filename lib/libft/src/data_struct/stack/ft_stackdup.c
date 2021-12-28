/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 18:56:48 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 15:40:44 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stack.h"

static void	populate(t_stack_elem **dest, t_stack_elem *src,
	t_content (*d)(t_content))
{
	if (!src)
	{
		*dest = NULL;
		return ;
	}
	*dest = ft_malloc(sizeof(t_stack_elem));
	if (d)
		(*dest)->cont = d(src->cont);
	else
		(*dest)->cont = src->cont;
	populate(&((*dest)->prev), src->prev, d);
}

t_stack	*ft_stackdup(t_stack *o, t_content(*dup)(t_content))
{
	t_stack	*ret;

	if (!o)
		return (NULL);
	ret = ft_malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	populate(&(ret->top), o->top, dup);
	ret->size = o->size;
	return (ret);
}
