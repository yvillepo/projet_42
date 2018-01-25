/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zomm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:39:42 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/25 03:36:19 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void		zoom(double *quantum, t_complex *cmin, t_complex *cmax, t_point *zoom_point)
{
	double		zoom;
	t_complex 	zoom_complex;

	zoom = PERCENT_ZOOM / 100.0;
	zoom_complex.r = cmin->r + *quantum * zoom_point->x;
	zoom_complex.i = cmin->i + *quantum * zoom_point->y;
	*quantum = *quantum / zoom;
	cmin->r = zoom_complex.r - (*quantum * zoom_point->x);
	cmin->i = zoom_complex.i - (*quantum * zoom_point->y);
	cmax->r = zoom_complex.r + (*quantum * zoom_point->x);
	cmax->i = zoom_complex.i + (*quantum * zoom_point->y);
}

static void		dezoom(double *quantum, t_complex *cmin, t_complex *cmax, t_point *zoom_point)
{
	double		zoom;
	t_complex 	zoom_complex;

	zoom = 1 / (PERCENT_ZOOM / 100.0);
	zoom_complex.r = cmin->r + *quantum * zoom_point->x;
	zoom_complex.i = cmin->i + *quantum * zoom_point->y;
	*quantum = *quantum / zoom;
	cmin->r = zoom_complex.r - (*quantum * zoom_point->x);
	cmin->i = zoom_complex.i - (*quantum * zoom_point->y);
	cmax->r = zoom_complex.r + (*quantum * zoom_point->x);
	cmax->i = zoom_complex.i + (*quantum * zoom_point->y);
}

void		zoom_fractale(t_mlx *mlx, t_point *zoom_point, int sens_zoom)
{
	t_complex	*cmin;
	t_complex	*cmax;

	cmin = cmin_fractole(mlx);
	cmax = cmax_fractole(mlx);
	if (mlx->fractale == MANDELBROT)
	{
		if (sens_zoom)
			zoom(&(mlx->mandelbrot->quantum), cmin, cmax, zoom_point);
		else
			dezoom(&(mlx->mandelbrot->quantum), cmin, cmax, zoom_point);
	}
	else if (mlx->fractale == JULIA)
	{
		if (sens_zoom)
			zoom(&(mlx->julia->quantum), cmin, cmax, zoom_point);
		else
			dezoom(&(mlx->julia->quantum), cmin, cmax, zoom_point);
	}
	affiche_fractal(mlx);
}
