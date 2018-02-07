/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 05:18:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/03 19:22:50 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_julia(t_mlx *mlx)
{
	mlx->julia->zmin->r = -2;
	mlx->julia->zmin->i = -2;
	mlx->julia->zmax->r = 2;
	mlx->julia->zmax->i = 2;
	mlx->julia->c->r = 0;
	mlx->julia->c->i = 0;
	mlx->fractale = JULIA;
	mlx->julia->mode_zoom = 0;
	init_quantum(mlx);
	julia_image(mlx);
}

void			open_julia(t_mlx *mlx)
{
	printf("one time\n");
	mlx->julia = ft_malloc(sizeof(*(mlx->julia)));
	mlx->julia->zmin = new_complex(-2, -2);
	mlx->julia->zmax = new_complex(2, 2);
	mlx->julia->c = new_complex(0, 0);
	init_julia(mlx);
	mlx_hook(mlx->win, 6, 1L < 6, input_julia, mlx);
}
