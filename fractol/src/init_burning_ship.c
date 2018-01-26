/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 07:28:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 09:29:33 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_burning_ship(t_mlx *mlx)
{
	mlx->burning->cmin = new_complex(-2.50, 1);
	mlx->burning->cmax = new_complex(-1.75, 1.75);
	mlx->burning->image.im = new_image(mlx, &(mlx->burning->image.pim));
	mlx->fractale = BURNING;
	init_quantum(mlx);
	burning_ship_image(mlx);
}

void			open_burning_ship(t_mlx *mlx)
{
	mlx->burning = ft_malloc(sizeof(*(mlx->burning)));
	init_burning_ship(mlx);
}
