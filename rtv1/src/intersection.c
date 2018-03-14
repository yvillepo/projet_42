#include "rtv1.h"

static void		calc_dir(t_mlx *mlx,t_vect *dir, int i, int j)
{
	t_vect	M;

	M.x = +(mlx->h / 2) - mlx->pitch * i;
	M.y = +(mlx->h / 2) - mlx->pitch * j;
	dir->x = M.x - mlx->camera_pos->x;
	dir->y = M.y - mlx->camera_pos->y;
	dir->z = 1;
}

double			intersec_unit(t_object	*obj, t_line *line)
{
	double	t;

	t = 0;
	if (obj->type == SPHERE)
		t = inter_sphere(obj->form, line);
	if (obj->type == PLANE)
		t = inter_plane(obj->form, line);
	return (t);
}

static t_color	calc(t_mlx *mlx, t_vect *dir, t_list *object)
{
	double			min;
	double			t;
	t_line			line;
	t_color			color;

	min = 100000000000000000;
	color.color = 0;
	line.origin = mlx->camera_pos;
	line.dir = dir;
	while (object)
	{
		t = intersec_unit(object->content, &line); 
		if (t < min && t > 0)
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
	calc_dir(mlx, &dir, i, j);
	return (calc(mlx, &dir, object)); 
}
