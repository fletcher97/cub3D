/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:35:42 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/14 00:35:50 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
**	ERRORS
*/

typedef enum e_errors {
	ILLEGAL_INPUT				= -1,
	FAILED_MALLOC				= -2,
	WRONG_EXTENSION				= -3,
	ERROR_READING_MAP_FILE		= -4,
	INVALID_MAP					= -5,
	ERROR_READING_IMAGE_FILE	= -6,
	NO_CONNECTION				= -7,
	NO_WINDOW					= -8,
	NO_IMG						= -9,
	REPEATED_ASSET				= -10,
	NO_MINIMAP_TEXTURES			= -11
}	t_errors;

#endif //ERRORS_H
