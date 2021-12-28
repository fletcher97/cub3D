/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:21:18 by mgueifao          #+#    #+#             */
/*   Updated: 2021/02/13 21:53:52 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_list.h"
#include "ft_stdlib.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	lst->content = NULL;
	lst->next = NULL;
	ft_free(lst);
}
