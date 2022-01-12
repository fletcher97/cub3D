/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_clear_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:09:19 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 02:13:03 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_err.h"
#include "ft_stdlib.h"

/**
 * Private function to clear the system
*/
void	p_clear_err(void)
{
	t_err	*err;
	t_err	*aux;

	err = p_get_err();
	while (err)
	{
		aux = err->next;
		ft_free(err->desc);
		ft_free(err);
		err = aux;
	}
}
