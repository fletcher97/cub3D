/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:31:26 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 02:11:54 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_err.h"

/**
 * Print the err message to stderr, clean the error system and exit with status
 * given as code
 * @param code The error code
*/
void	exit_err(int code)
{
	print_err(code, 2);
	p_clear_err();
	exit(code);
}
