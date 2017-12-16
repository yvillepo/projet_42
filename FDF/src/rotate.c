/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:22:12 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/16 00:29:30 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	rotate_z(t_mlx *m, double a)
{
	t_point3D	*p;
	int			nb_point;
	int			x;
	int			y;
	
	p = m->p3D;
	nb_point = m->nbpoint;
	x = p->x;
	y = p->y;
	while (nb_point--)
	{
		p->x = x * cos(a) - y * sin(a);
		p->y = x * sin(a) + y * cos(a);
		p++;
	}
	affiche(m);
}

void	rotate_x(t_mlx *m, double a)
{
	t_point3D	*p;
	int			nb_point;
	int			y;
	int			z;
	
	p = m->p3D;
	nb_point = m->nbpoint;
	y = p->y;
	z = p->z;
	while (nb_point--)
	{
		p->y = y * cos(a) - z * sin(a);
		p->z = y * sin(a) + z * cos(a);
		p++;
	}
	affiche(m);
}

void	rotate_y(t_mlx *m, double a)
{
	t_point3D	*p;
	int			nb_point;
	int			x;
	int			z;
	
	p = m->p3D;
	nb_point = m->nbpoint;
	x = p->x;
	z = p->z;
	while (nb_point--)
	{
		p->z = z * cos(a) - x * sin(a);
		p->x = z * sin(a) + x * cos(a);
		p++;
	}
	affiche(m);
}

void	rotate(t_mlx *m, char axe, double a)
{
	if (axe == 'z')
		rotate_z(m, a);
	if (axe == 'x')
		rotate_x(m, a);
	else
		rotate_y(m, a);
}

void	rotate_key(t_mlx *m, int key, double a)
{
	if (key == LEFT)
		rotate(m,'x', a);
	if (key == RIGHT)
		rotate(m,'x', -a);
	if (key == UP)
		rotate(m,'y', a);
	if (key == DOWN)
		rotate(m,'y', -a);
}
