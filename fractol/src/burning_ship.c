/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 07:12:30 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 10:13:46 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		is_limited(t_complex *c, int iteration_max, int order_color[3])
{
	int			i;
	t_complex	z;
	double		tmp_z_r;

	i = 0;
	z.r = 0;
	z.i = 0;
	while (i++ < iteration_max)
	{
		tmp_z_r = ft_abs_double(z.r * z.r - z.i * z.i + c->r);
		z.i = ft_abs_double(2 * z.r * z.i + c->i);
		z.r = tmp_z_r;
		if (z.r * z.r + z.i * z.i > 4)
			return (color2(1 - (double)i / (iteration_max), order_color));
	}
	return (0);
}

void			burning_ship_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = mlx->burning->cmin->i;
	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		c.r = mlx->burning->cmin->r;
		while (x < mlx->width)
		{
			fill_pixel(mlx, x, y,
					is_limited(&c, mlx->iteration, mlx->order_color));
			c.r += mlx->burning->quantum;
			x++;
		}
		c.i += mlx->burning->quantum;
		y++;
	}
	affiche(mlx);
}
