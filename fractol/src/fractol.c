/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 05:28:18 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/09 17:07:07 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			reset_fractole(t_mlx *mlx)
{
	if (mlx->fractale >= MANDELBROT)
		init_mandelbrot(mlx, mlx->fractale);
	if (mlx->fractale == JULIA)
		init_julia(mlx);
	if (mlx->fractale == BURNING)
		init_burning_ship(mlx);
}

void			read_fractol(t_mlx *mlx, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		open_mandelbrot(mlx, 2);
	else if (ft_strcmp(av[1], "mandelbrot3") == 0)
		open_mandelbrot(mlx, 3);
	else if (ft_strcmp(av[1], "mandelbrot4") == 0)
		open_mandelbrot(mlx, 4);
	else if (ft_strcmp(av[1], "mandelbrot5") == 0)
		open_mandelbrot(mlx, 5);
	else if (ft_strcmp(av[1], "mandelbrot6") == 0)
		open_mandelbrot(mlx, 6);
	else if (ft_strcmp(av[1], "julia") == 0)
		open_julia(mlx);
	else if (ft_strcmp(av[1], "burning") == 0)
		open_burning_ship(mlx);
	else
	{
		ft_putendl("USAGE : /fractol \"mandelbrot[3-6]\", \"julia\",\
\"burning\" [ [ ITERATION MAX ] [ TAILLE FENAITRE ] ]\n");
		exit(0);
	}
}

void			open_next_fractol(t_mlx *mlx, int sens)
{
	if (sens == -1 && mlx->fractale == 0)
		mlx->fractale = 6;
	else
		mlx->fractale = (mlx->fractale + sens) % 7;
	if (mlx->fractale >= MANDELBROT)
	{
		if (mlx->mandelbrot[mlx->fractale - 2] == NULL)
			open_mandelbrot(mlx, mlx->fractale);
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

void			up_iteration_max(t_mlx *mlx, double up)
{
	mlx->iteration *= up;
	if (mlx->iteration < 25)
		mlx->iteration = 25;
	affiche_fractal(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 20, 20,
			0xFFFFFF, ft_itoa(mlx->iteration));
}
