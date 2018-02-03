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
		mlx->mandelbrot[puissance - 2]->cmin = new_complex(-2.05, -1.4);
		mlx->mandelbrot[puissance - 2]->cmax = new_complex(0.80, 1.4);
	}
	else
	{
		mlx->mandelbrot[puissance - 2]->cmin = new_complex(-1.85, -1.4);
		mlx->mandelbrot[puissance - 2]->cmax = new_complex(1.00, 1.4);
	}
	mlx->mandelbrot[puissance - 2]->image.im =
		new_image(mlx, &(mlx->mandelbrot[puissance - 2]->image.pim));
	mlx->fractale = puissance;
	init_quantum(mlx);
	mandelbrot_image(mlx, puissance);
}

void			open_mandelbrot(t_mlx *mlx, int puissance)
{
	printf ("allocation mandelbrot \n");
	mlx->mandelbrot[puissance - 2] = ft_malloc(sizeof(**(mlx->mandelbrot)));
	printf ("ok\n");
	init_mandelbrot(mlx, puissance);
	printf ("ok2\n");
}
