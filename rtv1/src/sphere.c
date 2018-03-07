#include "rtv1.h"

void		read_sphere(t_sphere *sphere, int fd)
{
	char *line;

	sphere->centre = read_vect(fd);
	if (get_next_line(fd, &line) == 0)
		exit_error("fichier emtree");
	sphere->rayon = ft_atof(line);
	free (line);
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
	b = 2 * (dir->x * v.x + dir->y * v.y + dir->z * v.z);
	delta = b * b - 4 * a * (v.x * v.x + v.y * v.y + v.z * v.z -
			sphere->rayon * sphere->rayon); 
	if (delta >= 0)
	{
		t = (-b - sqrt(delta)) / (2 * a);
		res = new_vect(dir->x * t + mlx->camera_pos->x, dir->y
				* t + mlx->camera_pos->y, dir->z * t + mlx->camera_pos->z);
		return (t);
	}
	return (-1);
}
