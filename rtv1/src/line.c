/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:44:22 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 02:21:55 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect		*calc_point(t_line *line, double t)
{
	return (new_vect(line->origin->x + line->dir->x * t,
			line->origin->y + line->dir->y * t,
			line->origin->z + line->dir->z * t));
}

double		v_l(t_vect *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double		v_scale(t_vect *u, t_vect *v)
{
	return (u->x * v->x + u->y * u->y + u->z * u->z);
}

double		calc_angle(t_vect *v1, t_vect *v2)
{
	return (acos(v_mult(v1, v2) / (v_l(v1) * v_l(v2))));
}

void		v_unit(t_vect *v)
{
	double	norm;

	norm = v_l(v);
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
}
