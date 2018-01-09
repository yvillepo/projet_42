/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:22:12 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 10:33:51 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	rotate_z(t_mlx *m, double a)
{
	t_point3d		*p;
	int				nb_point;
	t_point			x;
	t_point			y;

	p = m->p;
	nb_point = m->nbpoint;
	while (nb_point--)
	{
		x = p->x;
		y = p->y;
		p->x = x * cos(a) - y * sin(a);
		p->y = y * cos(a) + x * sin(a);
		p++;
	}
	affiche(m);
}

void	rotate_x(t_mlx *m, double a)
{
	t_point3d	*p;
	int			nb_point;
	t_point		y;
	t_point		z;

	p = m->p;
	nb_point = m->nbpoint;
	while (nb_point--)
	{
		y = p->y;
		z = p->z;
		p->y = y * cos(a) - z * sin(a);
		p->z = y * sin(a) + z * cos(a);
		p++;
	}
	affiche(m);
}

void	rotate_y(t_mlx *m, double a)
{
	t_point3d	*p;
	int			nb_point;
	t_point		x;
	t_point		z;

	p = m->p;
	nb_point = m->nbpoint;
	while (nb_point--)
	{
		x = p->x;
		z = p->z;
		p->z = z * cos(a) - x * sin(a);
		p->x = z * sin(a) + x * cos(a);
		p++;
	}
	affiche(m);
}

void	rotate_key(t_mlx *m, int key, double a)
{
	if (key == RIGHT)
		rotate_z(m, a);
	else if (key == LEFT)
		rotate_z(m, -a);
	else if (key == UP)
		rotate_x(m, a);
	else if (key == DOWN)
		rotate_x(m, -a);
	else if (key == UN)
		rotate_y(m, a);
	else if (key == DEUX)
		rotate_y(m, -a);
}
