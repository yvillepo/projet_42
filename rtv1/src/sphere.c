#include "rtv1.h"

void		read_object_sphere(t_object *object, int fd)
{
		object->type = SPHERE;
		object->form = ft_malloc(sizeof(t_sphere));
		read_sphere(object->form, fd);
}

void		read_sphere(t_sphere *sphere, int fd)
{
	char *line;

	sphere->centre = read_vect(fd);
	if (get_next_line(fd, &line) == 0)
		exit_error("fichier emtree");
	sphere->rayon = ft_atof(line);
	free (line);
}

double			inter_sphere(t_sphere *sphere, t_line *line)
{
	double	a;
	double	b;
	double	delta;
	double	t;
	t_vect	*v;

	v = new_vect(line->origin->x - sphere->centre->x,
			line->origin->y - sphere->centre->y, line->origin->z - sphere->centre->z);
	a = line->dir->x * line->dir->x + line->dir->y * line->dir->y
		+ line->dir->z * line->dir->z;
	b = 2 * (line->dir->x * v->x + line->dir->y * v->y + line->dir->z * v->z);
	delta = b * b - 4 * a * (v->x * v->x + v->y * v->y + v->z * v->z -
			sphere->rayon * sphere->rayon); 
	free (v);
	if (delta >= 0)
	{
		t = (-b - sqrt(delta)) / (2 * a);
		return (t);
	}
	return (-1);
}

void		print_sphere(t_sphere *sphere)
{
	printf("sphere :\ncentre : %f %f %f\nR: %f\n", sphere->centre->x, sphere->centre->y,
			sphere->centre->z, sphere->rayon);
}