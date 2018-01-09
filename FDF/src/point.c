/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:29:23 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 10:11:24 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		fill_point(t_point3d *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

int			max_min_z(t_mlx *mlx)
{
	int			nbpoint;
	t_point3d	*p;
	int			zmin;
	int			zmax;

	p = mlx->p;
	zmin = p->z;
	zmax = p->z;
	nbpoint = mlx->nbpoint;
	while (nbpoint--)
	{
		if (p->z < zmin)
			zmin = p->z;
		if (p->z > zmax)
			zmax = p->z;
		p++;
	}
	mlx->z_min = zmin;
	return (zmax - zmin);
}

void		centrer_points(t_mlx *mlx)
{
	int				nbpoint;
	t_point3d		*p;
	int				dz;

	p = mlx->p;
	nbpoint = mlx->nbpoint;
	dz = max_min_z(mlx);
	mlx->max.z = ft_absd(dz);
	while (nbpoint--)
	{
		p->x -= (mlx->max.x) / 2.0;
		p->y -= (mlx->max.y) / 2.0;
		p->z -= dz / 2.0;
		p++;
	}
	mlx->z_min -= dz / 2;
}

void		translation(t_mlx *mlx, int key, int offset)
{
	if (key == T_A)
		mlx->centre.x += offset;
	if (key == T_D)
		mlx->centre.x -= offset;
	if (key == T_W)
		mlx->centre.y += offset;
	if (key == T_S)
		mlx->centre.y -= offset;
	affiche(mlx);
}
