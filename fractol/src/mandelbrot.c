/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 02:32:36 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdio.h>

int			color(int iteration, int iteration_max)
{
	return ((int)((float)iteration / iteration_max * 0xFFFFFF));
}

int			is_limited(t_complex *c, int iteration)
{
	int			i;
	t_complex	z;

	i = 0;
	z.i = 0;
	z.r = 0;
	while(i++ < iteration)
	{
		z = mult_complex(&z, &z);
		z = add_complex(&z, c);
		if (mod2(&z) > 4)
			return (color(i, iteration));
	}
	return (0);
}

void		centre(t_mlx *mlx)
{

	mlx->quantum = ft_min_double((mlx->c2->r - mlx->c1->r) / mlx->width,
			(mlx->c2->i - mlx->c1->i) / mlx->height);
	if ((mlx->c2->r - mlx->c1->r) / mlx->width < (mlx->c2->i - mlx->c1->i) / mlx->height)
	{
		mlx->c1->r = mlx->c1->r - (mlx->width * mlx->quantum - (mlx->c2->r - mlx->c1->r)) / 2.0;
		mlx->c2->r = mlx->c2->r + (mlx->width * mlx->quantum - (mlx->c2->r - mlx->c1->r)) / 2.0;
	}
	else
	{
		mlx->c1->i = mlx->c1->i + ((mlx->c2->i - mlx->c1->i) - (mlx->height * mlx->quantum)) / 2.0;
		mlx->c2->i = mlx->c2->i - ((mlx->c2->i - mlx->c1->i) - (mlx->height * mlx->quantum)) / 2.0;
	}
}

void		mandelbrot_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = mlx->c1->i;
	y = 0;
	printf("c = c1 = %f %f, c2 = %f %f quantum = %lf\n, with %d, height %d, iteration %d\n",mlx->c1->r, mlx->c1->i,
			mlx->c2->r, mlx->c2->i, mlx->quantum, mlx->width, mlx->height, mlx->iteration);
	while (y < mlx->height)
	{
		x = 0;
		c.r = mlx->c1->r;
		while (x < mlx->width)
		{
			fill_pixel(mlx, x, y, is_limited(&c, mlx->iteration));
			c.r += mlx->quantum;
			x++;
		}
		c.i += mlx->quantum;
		y++;
	}
	printf("c = %f %f= c2 = %f %f\n",c.r, c.i, mlx->c2->r, mlx->c2->i);
	affiche(mlx);
}

void		mandelbrot_image1(t_mlx *mlx, t_complex *c1, t_complex *c2)
{
	int		x;
	int		y;
	double		quantum_x;
	double		quantum_y;
	t_complex	c;

	quantum_x = (c2->r - c1->r) / mlx->width;
	quantum_y = (c2->i - c1->i) / mlx->height;
	c = *c1;
	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		c.r = c1->r;
		while (x < mlx->width)
		{
			if (is_limited(&c, mlx->iteration))
			{
				fill_pixel(mlx, x, y, 0xFFFFFF);
			}
			c.r += quantum_x;
			x++;
		}
		c.i += quantum_y;
		y++;
	}
	affiche(mlx);
}
