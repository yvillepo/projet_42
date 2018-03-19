/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:41:53 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/05 10:52:48 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect		*calc_point(t_line *line, double t)
{
	return (new_vect(line->origin->x + line->dir->x * t,
			line->origin->y + line->dir->y * t,
			line->origin->z + line->dir->z * t));
}

double	v_l(t_vect *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double	calc_angle(t_vect *v1, t_vect *v2)
{
	return (acos(v_mult(v1, v2) / (v_l(v1) * v_l(v2))));
}

void	v_unit(t_vect *v)
{
	double	norm;

	norm = v_l(v);
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
}

int		v_is_unit(t_vect *v)
{
	if (v_l(v) == 1)
		return (1);
	return (0);
}
void	v_print(t_vect *v)
{
	printf ("v : %f %f %f\n",v->x, v->y, v->z);
}

t_vect	*find_octo(t_vect *v)
{
	t_vect *res;

	res = 0;
	if(v->x !=0)
		res  = new_vect(-(v->y + v->z) / v->x, 1 , 1);
	else if(v->y !=0)
		res = new_vect(1, -(v->x + v->z) / v->y ,1);
	else if(v->z !=0)
		res = new_vect(1 , 1, -(v->x + v->y) / v->z);
	else
		exit_error("vecteur dir NULL");	
	v_unit(res);
	return (res);
}
