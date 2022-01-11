/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:18:41 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 15:34:36 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memutils.h"
#include <stdlib.h>

void	ft_free_matrix_s(void **matrix, int count, void (*del)(void *))
{
	int	i;
    
	if (!matrix || !del)
		return ;
	i = -1;
	while (++i < count)
		del(matrix[i]);
	free(matrix);
}

void	ft_free_matrix(void **matrix, void (*del)(void *))
{
	int	i;

	if (!matrix || !del)
		return ;
	i = -1;
	while (matrix[++i])
		del(matrix[i]);
	free(matrix);
}
