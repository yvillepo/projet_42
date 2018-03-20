/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:40:59 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 11:58:02 by yvillepo         ###   ########.fr       */
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
	t_vect	*va;

	plane->normal = read_vect(fd);
	va = read_vect(fd);
	plane->d = -(plane->normal->x * va->x + plane->normal->y * va->y +
			plane->normal->z * va->z);
	free(va);
}

double		inter_plane(t_plane *plane, t_line *line)
{
	double	d;

	d = line->dir->x * plane->normal->x + line->dir->y * plane->normal->y
			+ line->dir->z * plane->normal->z;
	if (d == 0)
		return (-1);
	d = (-((plane->normal->x * line->origin->x + plane->normal->y *
					line->origin->y + plane->normal->z
					* line->origin->z + plane->d) / d));
	return (d);
}
