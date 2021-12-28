/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:20:52 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 13:48:16 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *elem)
{
	t_list	*curr;

	curr = (*lst);
	if (!curr)
	{
		*lst = elem;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = elem;
}
