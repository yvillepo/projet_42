/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 05:28:18 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 07:50:22 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			reset_fractole(t_mlx *mlx)
{
	if (mlx->fractale == MANDELBROT)
		init_mandelbrot(mlx);
	if (mlx->fractale == JULIA)
		init_julia(mlx);
}

void			read_fractol(t_mlx *mlx, int ac, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		open_mandelbrot(mlx);
	else if (ft_strcmp(av[1], "julia") == 0)
		open_julia(mlx);
	else if (ft_strcmp(av[1], "burning") == 0)
		open_burning_ship(mlx);
	else
	{
		ft_putendl("USAGE : /fractol \"mandelbrot\", \"julia\",  [ [ ITERATION MAX ] [ TAILLE FENAITRE ] ]");
		exit (0);
	}
}

void			open_next_fractol(t_mlx *mlx)
{
	mlx->fractale = (mlx->fractale + 1) % 3;
	if (mlx->fractale == MANDELBROT)
	{
		if (mlx->mandelbrot == NULL)
			open_mandelbrot(mlx);
	}
	if (mlx->fractale == JULIA)
	{
		if (mlx->julia == NULL)
			open_julia(mlx);
	}
	if (mlx->fractale == BURNING)
	{
		if (mlx->burning == NULL)
			open_burning_ship(mlx);
	}
	affiche_fractal(mlx);
}

void			affiche_iteration_max(t_mlx *mlx)
{
	int		tmp;

	tmp = mlx->iteration;
	mlx->iteration = 500;
	affiche_fractal(mlx);
	mlx->iteration = tmp;
}
