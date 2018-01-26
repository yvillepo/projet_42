/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 05:19:46 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 05:20:51 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_mandelbrot(t_mlx *mlx)
{
		mlx->mandelbrot->cmin = new_complex(-2.05, -1.4);
		mlx->mandelbrot->cmax = new_complex(0.80, 1.4);
		mlx->mandelbrot->image.im = new_image(mlx, &(mlx->mandelbrot->image.pim));
		mlx->fractale = MANDELBROT;
		init_quantum(mlx);
		mandelbrot_image(mlx);
}

void			open_mandelbrot(t_mlx * mlx)
{
		mlx->mandelbrot = ft_malloc(sizeof(*(mlx->mandelbrot)));
		init_mandelbrot(mlx);
}
