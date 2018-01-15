/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/16 00:14:06 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdio.h>

int			is_limited(t_complex *c)
{
	int			i;
	t_complex	*z;

	i = ITERATION_MAX;
	z = new_complex(0, 0);
	while(i--)
	{
		*z = mult_complex(z, z);
		*z = add_complex(z, c);
		//printf("%f\n", mod2(z));
		if (mod2(z) > 4)
			return (0);
	}
	return (1);
}

void		centre(t_mlx *mlx)
{

	mlx->quantum = ft_min_double((mlx->c2->r - mlx->c1->r) / MAX_WIDTH,
			(mlx->c2->i - mlx->c1->i) / MAX_HEIGHT);
	if ((mlx->c2->r - mlx->c1->r) / MAX_WIDTH < (mlx->c2->i - mlx->c1->i) / MAX_HEIGHT)
	{
		mlx->c1->r = mlx->c1->r + ((mlx->c2->r - mlx->c1->r) - (MAX_WIDTH * mlx->quantum)) / 2;
		mlx->c2->r = mlx->c2->r - ((mlx->c2->r - mlx->c1->r) - (MAX_WIDTH * mlx->quantum)) / 2;
	}
		
	else
	{
		mlx->c1->i = mlx->c1->i + ((mlx->c2->i - mlx->c1->i) - (MAX_HEIGHT * mlx->quantum)) / 2;
		mlx->c2->i = mlx->c2->i - ((mlx->c2->i - mlx->c1->i) - (MAX_HEIGHT * mlx->quantum)) / 2;
	}
}

void		mandelbrot_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = mlx->c1->i;
	y = 0;
//	printf("c = c1 = %f %f, quantum = %lf\n",c.r, c.i, mlx->quantum);
	while (y < MAX_HEIGHT)
	{
		x = 0;
		c.r = mlx->c1->r;
		while (x < MAX_WIDTH)
		{
			if (is_limited(&c))
			{
				fill_pixel(mlx, x, y, 0xFFFFFF);
			}
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

	quantum_x = (c2->r - c1->r) / MAX_WIDTH;
	quantum_y = (c2->i - c1->i) / MAX_HEIGHT;
	c = *c1;
	y = 0;
	while (y < MAX_HEIGHT)
	{
		x = 0;
		c.r = c1->r;
		while (x < MAX_WIDTH)
		{
			if (is_limited(&c))
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
