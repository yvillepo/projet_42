#include "rtv1.h"

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

void	free_tab(char **tabstr)
{
	if (!tabstr)
		return ;
	while (*tabstr)
	{
		if (*tabstr)
			free(*tabstr);
		tabstr++;
	}
	*tabstr = NULL;
}

int             len_tabstr(char **tabstr)
{
	int             i;

	i = 0;
	while (*tabstr)
	{
		tabstr++;
		i++;
	}
	return (i);
}

void	free_tabstr(char ***tabstr)
{
	free_tab(*tabstr);
	if (*tabstr)
		free(*tabstr);
}

double	calc_height_screen(t_mlx *mlx)
{
	return (tan(mlx->fov / 2) * 2);
}
