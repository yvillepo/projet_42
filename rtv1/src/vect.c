/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:17:38 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 13:17:46 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*v_add(t_vect *u1, t_vect *u2)
{
	return (new_vect(u1->x + u2->x, u1->y + u2->y, u1->z + u2->z));
}

t_vect	*v_sub(t_vect *u1, t_vect *u2)
{
	return (new_vect(u1->x - u2->x, u1->y - u2->y, u1->z - u2->z));
}

t_vect	*v_cross(t_vect *u1, t_vect *u2)
{
	return (new_vect(u1->y * u2->z - u1->z * u2->y,
			u1->z * u2->x - u1->x * u2->z,
			u1->x * u2->y - u1->y * u2->x));
}

double	v_mult(t_vect *u1, t_vect *u2)
{
	return (u1->x * u2->x + u1->y * u2->y + u1->z * u2->z);
}
