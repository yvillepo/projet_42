/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 05:19:46 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/03 19:37:05 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_mandelbrot(t_mlx *mlx, int puissance)
{
	if (puissance == 2)
	{
		mlx->mandelbrot[puissance - 2]->cmin = new_complex(-2.00, -1.4);
		mlx->mandelbrot[puissance - 2]->cmax = new_complex(0.80, 1.4);
		mlx->mandelbrot[puissance - 2]->cmin->r = -2.00;
		mlx->mandelbrot[puissance - 2]->cmin->i = -1.40;
		mlx->mandelbrot[puissance - 2]->cmax->r = 0.80;
		mlx->mandelbrot[puissance - 2]->cmax->i = 1.40;
	}
	else
	{
		mlx->mandelbrot[puissance - 2]->cmin = new_complex(-1.50, -1.4);
		mlx->mandelbrot[puissance - 2]->cmax = new_complex(1.30, 1.4);
		mlx->mandelbrot[puissance - 2]->cmin->r = -1.50;
		mlx->mandelbrot[puissance - 2]->cmin->i = -1.4;
		mlx->mandelbrot[puissance - 2]->cmax->r = 1.30;
		mlx->mandelbrot[puissance - 2]->cmax->i = 1.4;
	}
	mlx->fractale = puissance;
	init_quantum(mlx);
	mandelbrot_image(mlx, puissance);
}

void			open_mandelbrot(t_mlx *mlx, int puissance)
{
	mlx->mandelbrot[puissance - 2] = ft_malloc(sizeof(**(mlx->mandelbrot)));
	if (puissance == 2)
	{
		mlx->mandelbrot[puissance - 2]->cmin = new_complex(-2.00, -1.4);
		mlx->mandelbrot[puissance - 2]->cmax = new_complex(0.80, 1.4);
	}
	else
	{
		mlx->mandelbrot[puissance - 2]->cmin = new_complex(-1.50, -1.4);
		mlx->mandelbrot[puissance - 2]->cmax = new_complex(1.30, 1.4);
	}
	init_mandelbrot(mlx, puissance);
}
