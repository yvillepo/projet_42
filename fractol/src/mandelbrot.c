/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/24 09:03:37 by yvillepo         ###   ########.fr       */
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

void		centre(t_mlx *mlx)
{
	t_complex 	*cmin;
	t_complex	*cmax;

	cmin = mlx->mandelbrot->cmin;
	cmax = mlx->mandelbrot->cmax;
	mlx->quantum = ft_min_double((cmax->r - cmin->r) / mlx->width,
			(cmax->i - cmin->i) / mlx->height);
	if ((cmax->r - cmin->r) / mlx->width < (cmax->i - cmin->i) / mlx->height)
	{
		cmin->r = cmin->r - (mlx->width * mlx->quantum - (cmax->r - cmin->r)) / 2.0;
		cmax->r = cmax->r + (mlx->width * mlx->quantum - (cmax->r - cmin->r)) / 2.0;
	}
	else
	{
		cmin->i = cmin->i - (mlx->height * mlx->quantum - (cmax->i - cmin->i)) / 2.0;
		cmax->i = cmax->i + (mlx->height * mlx->quantum - (cmax->i - cmin->i)) / 2.0;
	}
}

void		mandelbrot_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = mlx->mandelbrot->cmin->i;
	mlx->image = &(mlx->mandelbrot->image);
	y = 0;
//	printf("c = c1 = %f %f, c2 = %f %f quantum = %lf\n",mlx->c1->r, mlx->c1->i,
//				   mlx->c2->r, mlx->c2->i, mlx->quantum);
	printf("c = %f %f= c2 = %f %f\n",c.r, c.i, mlx->mandelbrot->cmax->r, mlx->mandelbrot->cmax->i);
	while (y < mlx->height)
	{
		x = 0;
		c.r = mlx->mandelbrot->cmin->r;
		while (x < mlx->width)
		{
			fill_pixel(mlx, x, y, is_limited(&c, mlx->iteration, mlx->order_color));
			c.r += mlx->quantum;
			x++;
		}
		c.i += mlx->quantum;
		y++;
	}
	printf("c = %f %f= c2 = %f %f\n",c.r, c.i, mlx->mandelbrot->cmax->r, mlx->mandelbrot->cmax->i);
	affiche(mlx);
}
