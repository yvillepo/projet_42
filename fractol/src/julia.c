/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:10:43 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 10:14:27 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		is_limited(t_complex *z0, t_complex *c,
		int iteration_max, int order_color[3])
{
	int			i;
	t_complex	z;
	double		tmp;

	i = 0;
	z.r = z0->r;
	z.i = z0->i;
	while (i++ < iteration_max)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c->r;
		z.i = 2 * (tmp * z.i) + c->i;
		if (z.r * z.r + z.i * z.i > 4)
			return (color2(1.0 - (double)i / (iteration_max), order_color));
	}
	return (0);
}

void			julia_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	z;

	z.i = mlx->julia->zmin->i;
	y = 0;
	mlx->image = &(mlx->julia->image);
	while (y < mlx->height)
	{
		x = 0;
		z.r = mlx->julia->zmin->r;
		while (x < mlx->width)
		{
			fill_pixel(mlx, x, y, is_limited(&z, mlx->julia->c,
						mlx->iteration, mlx->order_color));
			z.r += mlx->julia->quantum;
			x++;
		}
		z.i += mlx->julia->quantum;
		y++;
	}
	affiche(mlx);
}

void			switch_mode(t_julia *julia)
{
	if (julia->mode_zoom)
		julia->mode_zoom = 0;
	else
		julia->mode_zoom = 1;
}

int				input_julia(int x, int y, t_mlx *mlx)
{
	if (mlx->julia->mode_zoom || mlx->fractale != JULIA)
		return (0);
	mlx->julia->c->i = ((double)x / mlx->height) * 2 - 1;
	mlx->julia->c->r = ((double)y / mlx->width) * 2 - 1;
	julia_image(mlx);
	return (0);
}
