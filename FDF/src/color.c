/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:30:45 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 09:46:26 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		set_color(t_point3d *p, int r, int g, int b)
{
	p->c.rgb[0] = b;
	p->c.rgb[1] = g;
	p->c.rgb[2] = r;
	p->c.rgb[3] = 0;
}

void		color_point(t_mlx *mlx)
{
	int			nbpoint;
	int			dz;
	int			zmin;
	double		percent_color;
	t_point3d	*p;

	p = mlx->p;
	dz = mlx->max.z;
	zmin = mlx->z_min;
	nbpoint = mlx->nbpoint;
	while (nbpoint--)
	{
		if (dz == 0)
			percent_color = 0;
		else
			percent_color = (double)(p->z - zmin) / (double)dz;
		set_color(p, (0xFF * percent_color), (0xFF - 0xFF * percent_color),
				(0xFF - 0xFF * percent_color));
		p++;
	}
}
