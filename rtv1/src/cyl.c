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

void		read_cyl(t_cyl *cyl, int fd)
{
	char	*line;

	cyl->dir = read_vect(fd);
	cyl->pos = read_vect(fd);
	if(!get_next_line(fd, &line))
		exit_error("format input");
	cyl->r = ft_atof(line);
	free(line);
}

void		read_object_cyl(t_object *object, int fd)
{
	object->type = CYL;
	object->form = ft_malloc(sizeof(t_cyl));
	read_cyl(object->form, fd);
}

double	inter_cyl(t_cyl *cyl, t_line *l)
{
	t_vect 	*D;
	double	K;
	double	a;
	double	b;
	double	c;

	D = new_vect(l->origin->x - cyl->pos->x,l->origin->y - cyl->pos->y,
			l->origin->z - cyl->pos->z);
	K = 1 / (cyl->dir->x * cyl->dir->x + cyl->dir->y * cyl->dir->y +
		cyl->dir->z * cyl->dir->z);
	a = l->dir->x * l->dir->x + l->dir->y * l->dir->y + l->dir->z * l->dir->z -
		K * (cyl->dir->x * cyl->dir->x * l->dir->x * l->dir->x +
		cyl->dir->y * cyl->dir->y * l->dir->y * l->dir->y +
		cyl->dir->z * cyl->dir->z * l->dir->z * l->dir->z +
		2 * (
		cyl->dir->x * cyl->dir->y * l->dir->x * l->dir->y +
		cyl->dir->x * cyl->dir->z * l->dir->x * l->dir->z +
		cyl->dir->y * cyl->dir->z * l->dir->y * l->dir->z));
	b = 2 * (D->x * l->dir->x + D->y * l->dir->y + D->z * l->dir->z) - K *
		(2 * (cyl->dir->x * cyl->dir->x * l->dir->x * D->x +
			  cyl->dir->y * cyl->dir->y * l->dir->y * D->y +
			  cyl->dir->z * cyl->dir->z * l->dir->z * D->z +
		 cyl->dir->x * cyl->dir->y * (l->dir->x * D->y + l->dir->y * D->x) +
		 cyl->dir->x * cyl->dir->z * (l->dir->x * D->z + l->dir->z * D->x) +
		 cyl->dir->y * cyl->dir->z * (l->dir->y * D->z + l->dir->z * D->y)));
	c = D->x * D->x * (1 - K * cyl->dir->x * cyl->dir->x) + 
	D->y * D->y * (1 - K * cyl->dir->y * cyl->dir->y) +
	D->z * D->z * (1 - K * cyl->dir->z * cyl->dir->z) - 2 * K *
	(cyl->dir->x * cyl->dir->y * D->x * D->y +
	cyl->dir->x * cyl->dir->z * D->x * D->z +
	cyl->dir->y * cyl->dir->z * D->y * D->z) - cyl->r * cyl->r;
	return (solv_2nd(a, b, c));
}

void	print_cyl(t_cyl *cyl)
{
	printf("cyl :\ndir : %f %f %f\npositon : %f %f %f\nR = %f\n", cyl->dir->x, cyl->dir->y,
			cyl->dir->z, cyl->pos->x, cyl->pos->y, cyl->pos->z, cyl->r);
}
