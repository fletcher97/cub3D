/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:31:32 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 02:13:25 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdio.h"
#include "ft_err.h"

/**
 * Print the description associated with the error. Fails if no error with the
 * code given is found.
 * @param code The error code
 * @param fd The file descriptor to right to
 * @return 1 if successful, 0 if otherwise
*/
int	print_err(int code, int fd)
{
	t_err	*err;
	char	*msg;

	ft_putnbr_fd(code, fd);
	ft_putstr_fd(": ", fd);
	err = p_get_err();
	msg = NULL;
	if (err->desc)
	{
		while (err)
		{
			if (err->code == code)
			{
				msg = err->desc;
				break ;
			}
			err = err->next;
		}
	}
	if (msg)
		ft_putendl_fd(msg, fd);
	if (msg)
		return (1);
	ft_putendl_fd("Failed to get error msg", fd);
	return (0);
}
