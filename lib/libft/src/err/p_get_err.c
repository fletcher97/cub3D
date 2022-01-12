/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:52:29 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 02:12:51 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "ft_err.h"

/**
 * Private function to store the err struct
*/
t_err	*p_get_err(void)
{
	static t_err	*err = NULL;

	if (!err)
		err = ft_calloc(1, sizeof(t_err));
	return (err);
}
