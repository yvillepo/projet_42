/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/03 18:32:23 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		calcul(t_complex *c, t_complex *z, int puissance)
{
	double		tmp_z_r;
	t_complex	z_0;

	z_0.r = z->r;
	z_0.i = z->i;
	while (--puissance)
	{
		tmp_z_r = z->r * z_0.r - z->i * z_0.i;
		z->i = z->i * z_0.r + z->r * z_0.i;
		z->r = tmp_z_r;
	}
	z->r += c->r;
	z->i += c->i;
}

static int		is_limited(t_complex *c, int iteration_max,
		int puissance, int order_color[3])
{
	int			i;
	t_complex	z;

	i = 0;
	z.r = 0;
	z.i = 0;
	while (i++ < iteration_max)
	{
		calcul(c, &z, puissance);
		if (z.r * z.r + z.i * z.i > 4)
			return (color2(1 - (double)i / (iteration_max), order_color));
	}
	return (0);
}

void			mandelbrot_image(t_mlx *mlx, int puissance)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = mlx->mandelbrot[puissance - 2]->cmin->i;
	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		c.r = mlx->mandelbrot[puissance - 2]->cmin->r;
		while (x < mlx->width)
		{
			fill_pixel(mlx, x, y, is_limited(&c, mlx->iteration,
						puissance, mlx->order_color));
			c.r += (mlx->mandelbrot)[puissance - 2]->quantum;
			x++;
		}
		c.i += (mlx->mandelbrot)[puissance - 2]->quantum;
		y++;
	}
	affiche(mlx);
}
