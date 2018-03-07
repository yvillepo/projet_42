#include "rtv1.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		exit_error("arg");
	mlx = init(ac, av);
	parse(mlx, av[1]);
	trace_ray(mlx, mlx->object);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
