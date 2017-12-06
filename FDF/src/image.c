/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:56:18 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/06 20:26:00 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdio.h>

void	affiche(t_mlx *mlx)
{
	t_point3D	*p3D;
	int			nbpoint;

	p3D = mlx->p3D;
	nbpoint = mlx->nbpoint;
	while (nbpoint--)
	{
		mlx_pixel_put (mlx->mlx, mlx->win, p3D->x *  TAILLE_CARREAUX, p3D->y * TAILLE_CARREAUX, 0xFFFFFF);
//		printf ("%d : %d %d %d\n", nbpoint, p3D->x, p3D->y, p3D->z);
		p3D++;
	}
}
