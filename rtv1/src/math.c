#include "rtv1.h"

double		is_coplanar(t_vect *A, t_vect *B)
{
	double	p;

	p = B->x / A->x;
	if (A->y * p == B->y && A->z * p == B->z)
		return (p);
	return (0.0);
}

int		is_between(t_vect *A, t_vect *B, t_vect *M)
{
	t_line line;
	t_vect *um; 
	double	t;

	line.dir = new_vect(B->x - A->x, B->y - A->y, B->z - A->z);
	line.origin = A;
	um = new_vect(M->x - A->x, M->y - A->y, M->z - A->z);
	t = is_coplanar(line.dir, um);
	t = ft_abs_double(t);
	if (t == 0)
		return (-1);
	if (t > 1.0 || t < 0.0)
		return (0);
	return (1);
}

t_vect	unit_scale(double k, t_vect *v)
{
	t_vect res;

	res.x = v->x * k;
	res.y = v->y * k;
	res.z = v->z * k;
	return (res);
}

t_plane	*calc_plane(t_vect *normal, t_vect *A)
{
	t_plane	*p;

	p = ft_malloc(sizeof(*p));
	p->normal = normal;
	p->d = -(A->x  * normal->x + A->y * normal->y + A->z * normal->z);
	return (p);
}

double	solv_2nd(double a, double b, double c)
{
	double d;
	double res;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	res = (-b - sqrt(d)) / (2 * a);
	if (res < 0)
		res = (-b + sqrt(d)) / (2 * a);
	return (res);
}

double	deg_to_rad(double a)
{
	double ret;

	ret = a * PI / 180.0;
	return (ret);
}

void	print_vect(char *s, t_vect *v)
{
	printf("%s = %f %f %f\n",s, v->x, v->y, v->z);
}
