/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 10:54:14 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdio.h>


int			is_limited(t_complex *c, int iteration_max)
{
	int			i;
	t_complex	z;
	double		tmp_z_r;

	i = 0;
	z.r = 0;
	z.i = 0;
	while(i++ < iteration_max)
	{
		//z = mult_complex(&z, &z);
		//z = add_complex(&z, c);
		tmp_z_r = z.r * z.r - z.i * z.i + c->r;
		z.i = z.r * z.i + z.r * z.i + c->i;
		z.r = tmp_z_r;
		if (z.r * z.r + z.i * z.i > 4)
			return (color1(/*1.0 - */(double)i / (iteration_max)));
	}
	return (0);
}

void		centre(t_mlx *mlx)
{

	mlx->quantum = ft_min_double((mlx->c2->r - mlx->c1->r) / MAX_WIDTH,
			(mlx->c2->i - mlx->c1->i) / MAX_HEIGHT);
	if ((mlx->c2->r - mlx->c1->r) / MAX_WIDTH < (mlx->c2->i - mlx->c1->i) / MAX_HEIGHT)
	{
		mlx->c1->r = mlx->c1->r - (MAX_WIDTH * mlx->quantum - (mlx->c2->r - mlx->c1->r)) / 2.0;
		mlx->c2->r = mlx->c2->r + (MAX_WIDTH * mlx->quantum - (mlx->c2->r - mlx->c1->r)) / 2.0;
	}
	else
	{
		mlx->c1->i = mlx->c1->i + ((mlx->c2->i - mlx->c1->i) - (MAX_HEIGHT * mlx->quantum)) / 2.0;
		mlx->c2->i = mlx->c2->i - ((mlx->c2->i - mlx->c1->i) - (MAX_HEIGHT * mlx->quantum)) / 2.0;
	}
}

void		mandelbrot_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = mlx->c1->i;
	y = 0;
//	printf("c = c1 = %f %f, c2 = %f %f quantum = %lf\n",mlx->c1->r, mlx->c1->i,
//				   mlx->c2->r, mlx->c2->i, mlx->quantum);
	while (y < MAX_HEIGHT)
	{
		x = 0;
		c.r = mlx->c1->r;
		while (x < MAX_WIDTH)
		{
			fill_pixel(mlx, x, y, is_limited(&c, ITERATION_MAX));
			c.r += mlx->quantum;
			x++;
		}
		c.i += mlx->quantum;
		y++;
	}
//	printf("c = %f %f= c2 = %f %f\n",c.r, c.i, mlx->c2->r, mlx->c2->i);
	affiche(mlx);
}
