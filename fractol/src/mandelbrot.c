/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/13 02:50:35 by yvillepo         ###   ########.fr       */
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

void		mandelbrot_image(t_mlx *mlx, t_complex *c1, t_complex *c2)
{
	int		x;
	int		y;
	double		quantum;
	t_complex	c;

	quantum = ft_min_double((c2->r - c1->r) / MAX_WIDTH,
			(c2->i - c1->i) / MAX_HEIGHT);
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
			c.r += quantum;
			x++;
		}
		c.i += quantum;
		y++;
	}
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
