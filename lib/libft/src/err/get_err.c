/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:31:29 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 01:01:59 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_err.h"
#include "ft_string.h"

/**
 * Retrieve an error message given an error code
 * @param code The error code
 * @return A copy of the error message associated or null if no error with the
 * given error code exists
*/
char	*get_err(int code)
{
	t_err	*err;

	err = p_get_err();
	while (err->code != code)
		err = err->next;
	if (err->desc)
		return (ft_strdup(err->desc));
	return (NULL);
}
