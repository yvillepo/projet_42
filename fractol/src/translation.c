/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 05:02:10 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 06:42:16 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		translation(t_mlx *mlx, int key, double translation)
{
	if (key == LEFT)
	{
		translation = translation * (mlx->c1->r - mlx->c2->r);
		mlx->c1->r += translation;
		mlx->c2->r += translation;
	}
	else if (key == RIGHT)
	{
		translation = translation * (mlx->c1->r - mlx->c2->r);
		mlx->c1->r -= translation;
		mlx->c2->r -= translation;
	}
	else if (key == UP)
	{
		translation = translation * (mlx->c1->i - mlx->c2->i);
		mlx->c1->i += translation;
		mlx->c2->i += translation;
	}
	else if (key == DOWN)
	{
		translation = translation * (mlx->c1->i - mlx->c2->i);
		mlx->c1->i -= translation;
		mlx->c2->i -= translation;
	}
	printf ("trans :%f\n",translation);
	mandelbrot_image(mlx);
}
