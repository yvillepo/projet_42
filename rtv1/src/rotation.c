/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:11:04 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 13:12:13 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_z(t_vect *p, double a)
{
	double			x;
	double			y;

	x = p->x;
	y = p->y;
	p->x = x * cos(a) - y * sin(a);
	p->y = y * cos(a) + x * sin(a);
}

void	rotate_x(t_vect *p, double a)
{
	double		y;
	double		z;

	y = p->y;
	z = p->z;
	p->y = y * cos(a) - z * sin(a);
	p->z = y * sin(a) + z * cos(a);
}

void	rotate_y(t_vect *p, double a)
{
	double		x;
	double		z;

	x = p->x;
	z = p->z;
	p->z = z * cos(a) - x * sin(a);
	p->x = z * sin(a) + x * cos(a);
}

void	rotation(t_vect *v, t_vect *axe, double angle)
{

}
