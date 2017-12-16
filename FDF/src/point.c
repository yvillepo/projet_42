/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:29:23 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/16 01:48:25 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		fill_point(t_point3D *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

static int	max_min(t_mlx *mlx, int *zmin, int *zmax)
{
	int			nbpoint;
	t_point3D	*p;

	p = mlx->p3D;
	*zmin = p->z;
	*zmax = p->z;
	nbpoint = mlx->nbpoint;
	while (nbpoint--)
	{
		if (p->z < *zmin)
			*zmin = p->z;
		if (p->z > *zmax)
			*zmax = p->z;
		p++;
	}
	return (*zmax - *zmin);
}

void		centrer_points(t_mlx *mlx)
{
	int nbpoint;
	t_point3D *p;
	int			dz;
	int			zmax;

	p = mlx->p3D;
	nbpoint = mlx->nbpoint;
	dz = max_min(mlx, &dz, &zmax);
	while (nbpoint--)
	{
		p->x -= mlx->max.x / 2;
		p->y -= mlx->max.y / 2;
		p->z -= dz;
		p++;
	}	
}

void		zoom(t_mlx *mlx)
{
	if (mlx->scale <= 15)
		mlx->scale += 2;
	else if (mlx->scale <= 10)
		mlx->scale += 1;
	else
		mlx->scale += 5;
	affiche(mlx);
}

void		dezoom(t_mlx *mlx)
{
	if (mlx->scale <= 15)
		mlx->scale -= 2;
	else if (mlx->scale <= 10)
		mlx->scale -= 1;
	else
		mlx->scale -= 5;
	if (mlx->scale < 0)
		mlx->scale = 0;
	affiche(mlx);
}
