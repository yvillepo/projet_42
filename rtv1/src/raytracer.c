#include	"rtv1.h"

void		trace_ray(t_mlx *mlx, t_list *object)
{
	int		i;
	int		j;
	t_color	color;

	j = 0;
	while (j++ < mlx->height)
	{
		i = 0;
		while (i++ < mlx->width)
		{
			color = intersec(mlx, i, j, object);
			fill_pixel(mlx, i, j, color.color); 
		}
		affiche(mlx);
	}
}
