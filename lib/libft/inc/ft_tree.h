/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:43:25 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/22 21:48:35 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

typedef struct s_tree
{
	void			*content;
	int				lcount;
	struct s_tree	**leafs;
}				t_tree;

t_tree	*ft_treenew(void *content);
int		ft_treeadd(t_tree *tree, void *content);
int		ft_treeclear(t_tree *t, void (*del)(void *));

#endif
