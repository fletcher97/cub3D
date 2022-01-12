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
	*texture = voidp_to_matrix(tmp, img_height, img_width);
	mlx_destroy_image(mlx, tmp.img);
	if (!*texture)
		return (FAILED_MALLOC);
	else
		return (SUCCESSFUL_IMPORT);
}

/*
 *	Imports the pixel values (loaded by mlx) from a void * to an int matrix.
*/

int **voidp_to_matrix(t_img tmp, int height, int width)
{
	int x;
	int	y;
	int	**tex;

	tex = texture_init();
	if (tex)
	{
		y = -1;
		while (++y < height)
		{
			x = -1;
			while (++x < width)
				tex[y][x] = *(int *)(tmp.addr +
						(y * tmp.line + (x * (tmp.bpp / BITS_IN_BYTE))));
		}
	}
	return (tex);
}

/*
**	Initiates the matrices that are going to store the textures.
*/

int	**texture_init(void)
{
	int	i;
	int	**image;

	image = ft_calloc(TEXTURE_SIZE * 5 + NULL_TERM, sizeof(int *));
	if (!image)
		///error handling
	i = 0;
	while (i < TEXTURE_SIZE * 5)
	{
		image[i] = ft_calloc(TEXTURE_SIZE * 5, sizeof(int));
		if (!image[i])
		{
			ft_free_matrix((void**)image, NULL);
			///error handling
		}
		i++;
	}
	image[i] = NULL;
	return (image);
}
