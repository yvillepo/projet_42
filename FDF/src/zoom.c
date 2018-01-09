/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 23:48:45 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 11:08:20 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		zoom(t_mlx *mlx, double coef)
{
	t_point3d	*p;
	int			nbpoint;

	nbpoint = mlx->nbpoint;
	p = mlx->p;
	while (nbpoint--)
	{
		p->x = p->x * coef;
		p->y = p->y * coef;
		p->z = p->z * coef;
		p++;
	}
	affiche(mlx);
}

void		scale(t_mlx *mlx)
{
	t_point3d	*p;
	int			nbpoint;

	p = mlx->p;
	nbpoint = mlx->nbpoint;
	while (nbpoint--)
	{
		p->x = (p->x * mlx->scale);
		p->y = (p->y * mlx->scale);
		p->z = (p->z * mlx->scale);
		p++;
	}
	mlx->max.x = mlx->max.x * mlx->scale;
	mlx->max.y = mlx->max.y * mlx->scale;
}

void		def_scale(t_mlx *mlx)
{
	int		scalex;
	int		scaley;

	if (mlx->nbpoint == 1)
		return ;
	mlx->width_window = (SCALE_MAX * mlx->width + 0.30 * SCALE_MAX *
			ft_max(mlx->max.z, mlx->height)) * SECURE;
	mlx->height_window = (SCALE_MAX * mlx->height * 0.75 + SCALE_MAX *
			mlx->max.z * 0.70 + SCALE_MAX * 0.20 * mlx->width) * SECURE;
	if (mlx->height_window <= MAX_HEIGHT && mlx->width_window <= MAX_WIDTH)
	{
		mlx->scale = SCALE_MAX;
		return ;
	}
	if (mlx->width_window >= MAX_WIDTH)
		mlx->width_window = MAX_WIDTH;
	if (mlx->height_window >= MAX_HEIGHT)
		mlx->height_window = MAX_HEIGHT;
	scalex = (MAX_WIDTH / SECURE) / (mlx->width + 0.30 *
			ft_max(mlx->max.z, mlx->height));
	scaley = (MAX_HEIGHT / SECURE) / ((0.70 * mlx->height + 0.70 * mlx->max.z));
	mlx->scale = ft_min(scalex, scaley);
}
