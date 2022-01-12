/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:17:03 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 02:13:39 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_err.h"
#include "ft_string.h"
#include "ft_stdlib.h"

/**
 * Add a new error to the system. Function fails if an error with same code
 * already exists or desc is null.
 * @param code The error code
 * @param decs The error description
 * @return 1 if successful, 0 otherwise
*/
int	add_err(int code, char *desc)
{
	t_err	*err;

	if (!desc)
		return (0);
	err = p_get_err();
	if (!err->desc)
	{
		err->code = code;
		err->desc = ft_strdup(desc);
		return (1);
	}
	while (err)
	{
		if (err->code == code)
			return (0);
		if (!err->next)
			break ;
		err = err->next;
	}
	err->next = ft_calloc(1, sizeof(t_err));
	err->next->code = code;
	err->next->desc = ft_strdup(desc);
	return (1);
}
