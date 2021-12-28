/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:21:50 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 14:14:52 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_norm.h"
#include "ft_stdlib.h"

t_list	*ft_lstnew(void *conten)
{
	t_list	*elem;

	if (!(ft_set64((int64_t *)&elem, (int64_t)ft_malloc(sizeof(t_list)))))
		return (NULL);
	elem->content = conten;
	elem->next = NULL;
	return (elem);
}
