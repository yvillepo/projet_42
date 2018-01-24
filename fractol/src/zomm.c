/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zomm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:39:42 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/24 09:17:11 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(t_mlx *mlx, double percent_zoom, t_point *zoom_point)
{
	t_complex	zoom_complex;
	double		zoom;
	t_complex	*cmin;
	t_complex	*cmax;

	cmin = mlx->mandelbrot->cmin;
	cmax = mlx->mandelbrot->cmax;
	zoom = percent_zoom / 100;
	zoom_complex.r = cmin->r + mlx->quantum * zoom_point->x;
	zoom_complex.i = cmin->i + mlx->quantum * zoom_point->y;
	mlx->quantum = mlx->quantum / zoom;
	cmin->r = zoom_complex.r - (mlx->quantum * zoom_point->x);
	cmin->i = zoom_complex.i - (mlx->quantum * zoom_point->y);
	cmax->r = zoom_complex.r + (mlx->quantum * zoom_point->x);
	cmax->i = zoom_complex.i + (mlx->quantum * zoom_point->y);
	mandelbrot_image(mlx);
}
