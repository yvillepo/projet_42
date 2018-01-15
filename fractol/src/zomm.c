/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zomm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:39:42 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/16 00:29:29 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(t_mlx *mlx, double percent_zoom, t_point *zoom_point)
{
	t_complex	zoom_complex;
	double		zoom;

	zoom =  percent_zoom / 100;
	zoom_complex.r = mlx->c1->r + mlx->quantum * zoom_point->x;
	zoom_complex.i = mlx->c1->i + mlx->quantum * zoom_point->y;
	mlx->quantum = mlx->quantum / zoom;
	mlx->c1->r = zoom_complex.r - (mlx->quantum * zoom_point->x);
	mlx->c1->i = zoom_complex.i - (mlx->quantum * zoom_point->y);
	mlx->c2->r = zoom_complex.r + (mlx->quantum * zoom_point->x);
	mlx->c2->i = zoom_complex.i + (mlx->quantum * zoom_point->y);
	mandelbrot_image(mlx);
}
