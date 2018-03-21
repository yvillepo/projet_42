/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:31:11 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/21 19:09:00 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			read_cyl(t_cyl *cyl, int fd)
{
	char	*line;

	cyl->dir = read_vect(fd);
	cyl->pos = read_vect(fd);
	if (!get_next_line(fd, &line))
		exit_error("format input");
	cyl->r = ft_atof(line);
	free(line);
}

void			read_object_cyl(t_object *object, int fd)
{
	object->type = CYL;
	object->form = ft_malloc(sizeof(t_cyl));
	read_cyl(object->form, fd);
}

static double	calc_a(t_cyl *cyl, t_line *l, double k)
{
	return (l->dir->x * l->dir->x + l->dir->y * l->dir->y +
			l->dir->z * l->dir->z -
			k * (cyl->dir->x * cyl->dir->x * l->dir->x * l->dir->x +
				cyl->dir->y * cyl->dir->y * l->dir->y * l->dir->y +
				cyl->dir->z * cyl->dir->z * l->dir->z * l->dir->z +
				2 * (
				cyl->dir->x * cyl->dir->y * l->dir->x * l->dir->y +
				cyl->dir->x * cyl->dir->z * l->dir->x * l->dir->z +
				cyl->dir->y * cyl->dir->z * l->dir->y * l->dir->z)));
}

static double	calc_b(t_cyl *cyl, t_line *l, double k, t_vect *d)
{
	return (2 * (d->x * l->dir->x + d->y * l->dir->y + d->z * l->dir->z) - k *
		(2 * (cyl->dir->x * cyl->dir->x * l->dir->x * d->x +
		cyl->dir->y * cyl->dir->y * l->dir->y * d->y +
		cyl->dir->z * cyl->dir->z * l->dir->z * d->z +
		cyl->dir->x * cyl->dir->y * (l->dir->x * d->y + l->dir->y * d->x) +
		cyl->dir->x * cyl->dir->z * (l->dir->x * d->z + l->dir->z * d->x) +
		cyl->dir->y * cyl->dir->z * (l->dir->y * d->z + l->dir->z * d->y))));
}

double			inter_cyl(t_cyl *cyl, t_line *l)
{
	t_vect	*d;
	double	k;
	double	a;
	double	b;
	double	c;

	d = new_vect(l->origin->x - cyl->pos->x, l->origin->y - cyl->pos->y,
			l->origin->z - cyl->pos->z);
	k = 1 / (cyl->dir->x * cyl->dir->x + cyl->dir->y * cyl->dir->y +
		cyl->dir->z * cyl->dir->z);
	a = calc_a(cyl, l, k);
	b = calc_b(cyl, l, k, d);
	c = d->x * d->x * (1 - k * cyl->dir->x * cyl->dir->x) +
	d->y * d->y * (1 - k * cyl->dir->y * cyl->dir->y) +
	d->z * d->z * (1 - k * cyl->dir->z * cyl->dir->z) - 2 * k *
	(cyl->dir->x * cyl->dir->y * d->x * d->y +
	cyl->dir->x * cyl->dir->z * d->x * d->z +
	cyl->dir->y * cyl->dir->z * d->y * d->z) - cyl->r * cyl->r;
	return (solv_2nd(a, b, c));
}
