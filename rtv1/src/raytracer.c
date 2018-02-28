#include	"wolf.h"

static void		calc_dir(t_mlx *mlx,t_vect *dir, int i, int j)
{
	dir->x = mlx->pitch->x * i;
	dir->y = mlx->pitch->y * j;
	dir->z = 1;
}

double			inter_sphere(t_mlx *mlx, t_vect *dir, t_sphere *sphere, t_vect *res)
{
	double	a;
	double	b;
	double	delta;
	double	t;
	t_vect	v;

	v.x = mlx->camera_pos->x - sphere->centre->x;
	v.y = mlx->camera_pos->y - sphere->centre->y;
	v.z = mlx->camera_pos->z - sphere->centre->z;
	a = dir->x * dir->x + dir->y * dir->y + dir->z * dir->z; 
	b = 2 *  dir->x * v.x + dir->y * v.y + dir->z * v.z;
	delta = b * b - 4 * a * (v.x * v.x + v.y * v.y + v.z * v.z); 
	if (delta > 0)
	{
		t = (-b - sqrt(delta)) / (2 * a);
		res->x = dir->x * t + sphere->centre->x;
		res->y = dir->y * t + sphere->centre->y;
		res->z = dir->z * t + sphere->centre->z;
		return (t);
	}
	return (-1);
}

static t_color	calc(t_mlx *mlx, t_vect *dir, t_list *object)
{
	t_vect			*intersec;
	t_vect			res;
	double			min;
	double			t;
	t_color			color;

	min = -1;
	color.color = 0;
	while (object)
	{
		if (((t_object*)object->content)->form == SPHERE)
		{
			t = inter_sphere(mlx, dir,
					((t_object*)object->content)->form, &res);
		}
		if (t < min && t > 0)
		{
			color =  ((t_object*)object->content)->color;
			min = t;
		}
		object = object->next;
	};
	return (color);
}

t_color			intersec(t_mlx *mlx, int i, int j, t_list *object)
{
	double		t;
	t_vect		dir;
	t_list		*current;
	double		min;

	min = 0;
	calc_dir(mlx, &dir, i, j);
	return (calc(mlx, &dir, object)); 
}

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
	}
}

