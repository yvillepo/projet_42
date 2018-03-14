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

void		find_octo(t_vect *base, t_vect *y, t_vect *x)
{
	
}

void		read_cyl(t_cyl *cyl, int fd)
{
	t_vect	*A;

	cyl->angle = read_vect(fd);
	cyl->pos = read_vect(fd);
}

void		read_object_cyl(t_object *object, int fd)
{
	object->type = CYL;
	object->form = ft_malloc(sizeof(t_cyl));
	read_cyl(object->form, fd);
}


double	inter_cyl(t_plane *plane, t_line *line)
{

}

void	print_cyl(t_cyl *cyl)
{
	printf("plane :\nangle : %f %f %f\n positon : %f\n", cyl->angle->x, cyl->angle->y,
			cyl->angle->z, cyl->pos->x, cyl->pos->y, cyl->pos->z);
}
