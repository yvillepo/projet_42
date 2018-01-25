/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 00:46:03 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/25 02:54:50 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_complex		*cmin_fractole(t_mlx *mlx)
{
	if (mlx->fractale == MANDELBROT)
		return (mlx->mandelbrot->cmin);
	else if (mlx->fractale == JULIA)
		return (mlx->julia->zmin);
	return (NULL);
}

t_complex		*cmax_fractole(t_mlx *mlx)
{
	if (mlx->fractale == MANDELBROT)
		return (mlx->mandelbrot->cmax);
	else if (mlx->fractale == JULIA)
		return (mlx->julia->zmax);
	return (NULL);
}

static double	calc_quantum(t_mlx *mlx, t_complex *cmin, t_complex *cmax)
{
	return (ft_min_double((cmax->r - cmin->r) / mlx->width,
			(cmax->i - cmin->i) / mlx->height));
}

void			init_quantum(t_mlx *mlx)
{
	t_complex 	*cmin;
	t_complex	*cmax;

	cmin = cmin_fractole(mlx);
	cmax = cmax_fractole(mlx);
	if (mlx->fractale == MANDELBROT)
		mlx->mandelbrot->quantum =calc_quantum(mlx, cmin, cmax);
	if (mlx->fractale == JULIA)
		mlx->julia->quantum =calc_quantum(mlx, cmin, cmax);
}
/*
void		init_quantum(t_mlx *mlx)
{
	t_complex 	*cmin;
	t_complex	*cmax;

	cmin = cmin_fractole(mlx);
	cmax = cmax_fractole(mlx);
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
}*/
