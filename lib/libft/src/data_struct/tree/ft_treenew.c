/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:48:28 by mgueifao          #+#    #+#             */
/*   Updated: 2021/10/16 21:14:24 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"
#include "ft_stdlib.h"

t_tree	*ft_treenew(void *content)
{
	t_tree	*ret;

	ret = ft_calloc(1, sizeof(t_tree));
	if (!ret)
		return (NULL);
	ret->content = content;
	return (ret);
}
