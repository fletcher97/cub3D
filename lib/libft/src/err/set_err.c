/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:31:35 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 01:07:19 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_err.h"
#include "ft_string.h"
#include "ft_stdlib.h"

/**
 * Change the description of a given error. Fails if no error with the
 * given code is found.
 * @param code The error code
 * @param desc The new description
 * @return 1 if successful, 0 otherwise
*/
int	set_err(int code, char *desc)
{
	t_err	*err;

	err = p_get_err();
	if (!err->desc || !desc)
		return (0);
	while (err)
	{
		if (err->code == code)
		{
			ft_free(err->desc);
			err->desc = ft_strdup(desc);
			return (1);
		}
		err = err->next;
	}
	return (0);
}
