/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 00:46:03 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/09 17:06:30 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		*cmin_fractole(t_mlx *mlx)
{
	if (mlx->fractale >= MANDELBROT)
		return ((mlx->mandelbrot[mlx->fractale - 2])->cmin);
	else if (mlx->fractale == JULIA)
		return (mlx->julia->zmin);
	if (mlx->fractale == BURNING)
		return (mlx->burning->cmin);
	return (NULL);
}

t_complex		*cmax_fractole(t_mlx *mlx)
{
	if (mlx->fractale >= MANDELBROT)
		return ((mlx->mandelbrot[mlx->fractale - 2])->cmax);
	else if (mlx->fractale == JULIA)
		return (mlx->julia->zmax);
	if (mlx->fractale == BURNING)
		return (mlx->burning->cmax);
	return (NULL);
}

static double	calc_quantum(t_mlx *mlx, t_complex *cmin, t_complex *cmax)
{
	return (ft_min_double((cmax->r - cmin->r) / mlx->width,
			(cmax->i - cmin->i) / mlx->height));
}

void			init_quantum(t_mlx *mlx)
{
	t_complex	*cmin;
	t_complex	*cmax;

	cmin = cmin_fractole(mlx);
	cmax = cmax_fractole(mlx);
	if (mlx->fractale >= MANDELBROT)
		mlx->mandelbrot[mlx->fractale - 2]->quantum =
			calc_quantum(mlx, cmin, cmax);
	if (mlx->fractale == JULIA)
		mlx->julia->quantum = calc_quantum(mlx, cmin, cmax);
	if (mlx->fractale == BURNING)
		mlx->burning->quantum = calc_quantum(mlx, cmin, cmax);
}
