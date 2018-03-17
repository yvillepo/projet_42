/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:40:59 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/05 10:55:31 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		read_object_plane(t_object *object, int fd)
{
	object->type = PLANE;
	object->form = ft_malloc(sizeof(t_plane));
	read_plane(object->form, fd);
}

void		read_plane(t_plane *plane, int fd)
{
	t_vect	*A;

	plane->normal = read_vect(fd);
	A = read_vect(fd);
	plane->d = -(plane->normal->x * A->x + plane->normal->y * A->y +
			plane->normal->z * A->z);
	free (A);
}

double	inter_plane(t_plane *plane, t_line *line)
{
	double	d;
	
	d = line->dir->x * plane->normal->x + line->dir->y * plane->normal->y 
			+ line->dir->z * plane->normal->z;
	if (d == 0)
		return (-1);
	d =(-((plane->normal->x * line->origin->x + plane->normal->y *
					line->origin->y + plane->normal->z * line->origin->z + plane->d) / d));
	return (d);
}

void	print_plane(t_plane *plane)
{
	printf("plane :\nnomrmal : %f %f %f\nd : %f\n", plane->normal->x, plane->normal->y,
			plane->normal->z, plane->d);
}

t_vect	*p_normal(t_vect *u, t_vect *v)
{
	t_vect	*res;

	res = ft_malloc(sizeof(*res));
	res->x = 1;
	res->y = res->x * (u->x - v->x * u->z / v->z) / (v->y * u->z / v->z - u->y); 
	res->z = -(res->x * v->x + res->y * v->y) / v->z;
	v_unit(res);	
	return (res);
}
