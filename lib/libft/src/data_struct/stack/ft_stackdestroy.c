/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdestroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:51:24 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 15:34:40 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stack.h"

void	ft_stackdestroy(t_stack *stack, void (*del)(t_content))
{
	while (ft_stacksize(stack))
	{
		if (del)
			del(ft_stackpop(stack));
		else
			ft_stackpop(stack);
	}
	ft_free(stack);
}
