/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 07:28:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/03 19:15:44 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_burning_ship(t_mlx *mlx)
{
	mlx->burning->cmin->r = -2.20;
	mlx->burning->cmin->i = -2.25;
	mlx->burning->cmax->r = 1.30;
	mlx->burning->cmax->i = 1.25;
	mlx->fractale = BURNING;
	init_quantum(mlx);
	burning_ship_image(mlx);
}

void			open_burning_ship(t_mlx *mlx)
{
	mlx->burning = ft_malloc(sizeof(*(mlx->burning)));
	mlx->burning->image.im = new_image(mlx, &(mlx->burning->image.pim));
	mlx->burning->cmin = new_complex(-2.20, -2.25);
	mlx->burning->cmax = new_complex(1.30, 1.25);
	init_burning_ship(mlx);
}
