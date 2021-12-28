/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:03:41 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 15:39:36 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stack.h"

void	ft_stackpush(t_stack *stack, t_content content)
{
	t_stack_elem	*new;

	new = ft_malloc(sizeof(t_stack_elem));
	new->cont = content;
	new->prev = stack->top;
	stack->top = new;
	stack->size++;
}
