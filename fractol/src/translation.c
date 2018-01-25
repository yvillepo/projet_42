/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 05:02:10 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/25 03:40:13 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		translation_base(t_complex *cmin, t_complex *cmax, int key, double translation)
{
	if (key == LEFT)
	{
		translation = translation * (cmin->r - cmax->r);
		cmin->r += translation;
		cmax->r += translation;
	}
	else if (key == RIGHT)
	{
		translation = translation * (cmin->r - cmax->r);
		cmin->r -= translation;
		cmax->r -= translation;
	}
	else if (key == UP)
	{
		translation = translation * (cmin->i - cmax->i);
		cmin->i += translation;
		cmax->i += translation;
	}
	else if (key == DOWN)
	{
		translation = translation * (cmin->i - cmax->i);
		cmin->i -= translation;
		cmax->i -= translation;
	}
}

void		translation_fractale(t_mlx *mlx, int key, double translation)
{
	if (mlx->fractale == 0)
	{
		translation_base(mlx->mandelbrot->cmin, mlx->mandelbrot->cmax,
				key, translation);
		mandelbrot_image(mlx);
	}
	if (mlx->fractale == 1)
	{
		translation_base(mlx->julia->zmin, mlx->julia->zmax,
				key, translation);
		julia_image(mlx);
	}
}
