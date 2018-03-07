#include "rtv1.h"

void			calc_pitch(t_mlx *mlx)
{
	mlx->h = calc_height_screen(mlx);
	mlx->pitch = mlx->h / mlx->height;
}

static void		calc_dir(t_mlx *mlx,t_vect *dir, int i, int j)
{
	t_vect	M;

	M.x = -(mlx->h / 2) + mlx->pitch * i;
	M.y = -(mlx->h / 2) + mlx->pitch * j;
	dir->x = M.x - mlx->camera_pos->x;
	dir->y = M.y - mlx->camera_pos->y;
	dir->z = 1;
}

static t_color	calc(t_mlx *mlx, t_vect *dir, t_list *object)
{
	t_vect			*res;
	double			min;
	double			t;
	t_color			color;

	min = -1;
	color.color = 0;
	res = NULL;
	while (object)
	{
		if (((t_object*)(object->content))->type == SPHERE)
		{
			t = inter_sphere(mlx, dir,
					((t_object*)object->content)->form, res);
		}
		if (t > min && t >= 0)
		{
			color =  ((t_object*)object->content)->color;
			min = t;
		}
		object = object->next;
	}
	return (color);
}

t_color			intersec(t_mlx *mlx, int i, int j, t_list *object)
{
	t_vect		dir;
	double		min;

	min = 0;
	calc_pitch(mlx);
	calc_dir(mlx, &dir, i, j);
	return (calc(mlx, &dir, object)); 
}

