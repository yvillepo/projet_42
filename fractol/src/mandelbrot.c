/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/25 03:41:02 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdio.h>


static int			is_limited(t_complex *c, int iteration_max, int order_color[3])
{
	int			i;
	t_complex	z;
	double		tmp_z_r;

	i = 0;
	z.r = 0;
	z.i = 0;
	while(i++ < iteration_max)
	{
		tmp_z_r = z.r * z.r - z.i * z.i + c->r;
		z.i = 2 * z.r * z.i+ c->i;
		z.r = tmp_z_r;
		if (z.r * z.r + z.i * z.i > 4)
			return (color2(1 - (double)i / (iteration_max), order_color));
	}
	return (0);
}


void		mandelbrot_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = mlx->mandelbrot->cmin->i;
	mlx->image = &(mlx->mandelbrot->image);
	y = 0;
//	printf("c1 = %f %f= c2 = %f %f\n quantum = %f\n", mlx->mandelbrot->cmin->r,mlx->mandelbrot->cmin->i, mlx->mandelbrot->cmax->r, mlx->mandelbrot->cmax->i, mlx->mandelbrot->quantum);
	while (y < mlx->height)
	{
		x = 0;
		c.r = mlx->mandelbrot->cmin->r;
		while (x < mlx->width)
		{
			fill_pixel(mlx, x, y, is_limited(&c, mlx->iteration, mlx->order_color));
			c.r += mlx->mandelbrot->quantum;
			x++;
		}
		c.i += mlx->mandelbrot->quantum;
		y++;
	}
//	printf("c = %f %f= c2 = %f %f\n",c.r, c.i, mlx->mandelbrot->cmax->r, mlx->mandelbrot->cmax->i);
	affiche(mlx);
}
