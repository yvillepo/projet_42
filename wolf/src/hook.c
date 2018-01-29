#include "wolf.h"
#include "libft.h"

int		key_hook(int keycode, void *p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)(p);

	if (keycode == ECHAP)
		exit (0);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
//	p = new_point(x, y);
	if (button == 5 || button == 1)
		edit_block(mlx, x, y); 
	if (button == 4)
		;
	return (0);
}
