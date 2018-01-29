#include "wolf.h"
#include <stdio.h> 

int		main(void)
{
	t_mlx	*mlx;

	mlx = init();
	mlx_key_hook(mlx->win, key_hook, mlx);
	printf ( "init/key_hook ok \n");
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
}
