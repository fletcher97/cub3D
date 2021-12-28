/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:06:17 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/22 21:28:53 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"
#include "ft_stdlib.h"

int	ft_treeadd(t_tree *tree, void *content)
{
	t_tree	*new;

	new = ft_treenew(content);
	if (!new)
		return (0);
	tree->leafs = ft_realloc(tree->leafs, tree->lcount * sizeof(t_tree),
			(tree->lcount + 1) * sizeof(t_tree));
	tree->leafs[tree->lcount++] = new;
	return (1);
}
