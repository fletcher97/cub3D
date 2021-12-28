/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_treeclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:43:17 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/22 21:48:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_tree.h"

int	ft_treeclear(t_tree *t, void (*del)(void *))
{
	if (!t)
		return (0);
	del(t->content);
	while (t->lcount)
		ft_treeclear(t->leafs[--t->lcount], del);
	free(t->leafs);
	free(t);
	return (1);
}
