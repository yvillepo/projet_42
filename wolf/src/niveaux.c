#include "wolf.h"
#include <stdio.h>

void	draw_block(t_mlx *mlx, int x, int y, int texture)
{
	int		i;
	int		j;

	i = 0;
	x = (x / SIZE_BLOCK) * SIZE_BLOCK;
	y = (y / SIZE_BLOCK) * SIZE_BLOCK;
	if (x + SIZE_BLOCK > WIDTH 	|| y + SIZE_BLOCK > HEIGHT)
		return ;
	while (i < SIZE_BLOCK)
	{
		j = 0;	
		while (j < SIZE_BLOCK)
		{
			if (i == 0 || j == 0 || i == SIZE_BLOCK - 1 || j == SIZE_BLOCK -1)
				fill_pixel(mlx, x + j, y + i, 0X888888);
			else
				fill_pixel(mlx, x + j, y + i, (texture / NB_TEXTURE) * 0XFFFFFF);
			j++;
		}
		i++;
	}
	affiche (mlx);
}

void 	edit_block(t_mlx *mlx, int x, int y)
{
//	mlx->map[x][y] = mlx->texture;
	draw_block (mlx, x, y, mlx->texture);
}
