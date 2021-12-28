/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:14:57 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 15:25:34 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stack.h"

t_content	ft_stackpop(t_stack *stack)
{
	t_content		ret;
	t_stack_elem	*tmp;

	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->size--;
	ret = tmp->cont;
	ft_free(tmp);
	return (ret);
}
