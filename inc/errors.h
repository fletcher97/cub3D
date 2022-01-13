#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

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

#endif

