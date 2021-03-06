/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:38:11 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/03 18:07:35 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	*new_image(t_mlx *mlx, void **image)
{
	int a;
	int	b;
	int c;

	*image = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	return ((unsigned int*)mlx_get_data_addr(*image, &a, &b, &c));
}

void			fill_pixel(t_mlx *mlx, int x1,
		int y1, unsigned int color)
{
	int		x;
	int		y;

	x = x1;
	y = y1;
	if (x >= mlx->width || y >= mlx->height || x <= 0 || y <= 0)
		return ;
	mlx->image.im[x + y * mlx->width] = color;
}

void			affiche(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.pim, 0, 0);
}

void			affiche_fractal(t_mlx *mlx)
{
	if (mlx->fractale >= MANDELBROT)
		mandelbrot_image(mlx, mlx->fractale);
	if (mlx->fractale == JULIA)
		julia_image(mlx);
	if (mlx->fractale == BURNING)
		burning_ship_image(mlx);
}
