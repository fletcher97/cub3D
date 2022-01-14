/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:51:54 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/13 23:55:10 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_memutils.h"

#include "c3d_map.h"
#include "mlx.h"
#include "errors.h"

/*
 *	Imports from the xpm file found on path "path" to a void* located in the tmp
 *	struct. Then imports from that void* to a matrix (int**), and saves that
 *	pixel matrix to *texture.
*/

int	load_tex(void *mlx, int ***texture, char *path)
{
	t_img		tmp;
	int			img_height;
	int			img_width;

	tmp.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	if (!tmp.img)
		return (NO_IMG);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.line, &tmp.endian);
	if (texture_init(texture))
		voidp_to_matrix(tmp, texture, img_height, img_width);
	mlx_destroy_image(mlx, tmp.img);
	if (!*texture)
		return (FAILED_MALLOC);
	return (SUCCESSFUL_IMPORT);
}

/*
 *	Imports the pixel values (loaded by mlx) from a void * to an int matrix.
*/

void	voidp_to_matrix(t_img tmp, int ***texture, int height, int width)
{
	int				x;
	int				y;
	unsigned char	*c;

	if (*texture)
	{
		y = -1;
		while (++y < height)
		{
			x = -1;
			while (++x < width)
			{
				c = (unsigned char *)tmp.addr + (y * tmp.line + (x * (tmp.bpp
								/ BITS_PER_BYTE)));
				(*texture)[y][x] = (unsigned int)c[0] << 24 | c[1] << 16
					| c[2] << 8 | c[3];
			}
		}
	}
}

/*
**	Initiates the matrices that are going to store the textures.
*/

int	texture_init(int ***tex)
{
	int	i;

	*tex = ft_calloc(TEXTURE_SIZE * 5 + NULL_TERM, sizeof(int *));
	if (!*tex)
		return (0);
	i = 0;
	while (i < TEXTURE_SIZE * 5)
	{
		(*tex)[i] = ft_calloc(TEXTURE_SIZE * 5, sizeof(int));
		if (!(*tex)[i])
		{
			ft_free_matrix((void **)*tex, NULL);
			return (0);
		}
		i++;
	}
	(*tex)[i] = NULL;
	return (1);
}
