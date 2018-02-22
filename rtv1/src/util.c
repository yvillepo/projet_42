#include "wolf.h"

t_vect	*new_vect(double x, double y, double z)
{
	t_vect	*new;

	new = ft_memalloc(sizeof(*new));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_point	*new_point(double x, double y)
{
	t_point	*new;

	new = ft_memalloc(sizeof(*new));
	new->x = x;
	new->y = y;
	return (new);
}
