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

double	inter_plane(t_plane *plane, t_line *line, t_vect *res)
{
	double t;

	t = -((plane->normal->x * line->origin->x + plane->normal->y * line->origin->y +
		plane->normal->z * line->origin->z + plane->d) /
		(line->dir->x + line->dir->y + line->dir->z ));
	calc_point(line, t, res);
	return (t);
}
