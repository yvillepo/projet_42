/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:12:49 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/21 17:58:36 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	sphere->rayon = ft_atof(line) / 2;
	free(line);
}

double		inter_sphere(t_sphere *sphere, t_line *line)
{
	double	a;
	double	b;
	double	t;
	t_vect	*v;

	v = new_vect(line->origin->x - sphere->centre->x,
			line->origin->y - sphere->centre->y,
			line->origin->z - sphere->centre->z);
	a = line->dir->x * line->dir->x + line->dir->y * line->dir->y
		+ line->dir->z * line->dir->z;
	b = 2 * (line->dir->x * v->x + line->dir->y * v->y + line->dir->z * v->z);
	t = solv_2nd(a, b, (v->x * v->x + v->y * v->y + v->z * v->z -
			sphere->rayon * sphere->rayon));
	free(v);
	return (t);
}
