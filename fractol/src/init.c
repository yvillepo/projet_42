/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/25 05:05:51 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void		init_order_color(int order_color[3])
{
	order_color[0] = 2;
	order_color[1] = 1;
	order_color[2] = 0;
}

void			init_julia(t_mlx *mlx)
{
	mlx->julia->zmin = new_complex(-2, -2);
	mlx->julia->zmax = new_complex(2, 2);
	mlx->julia->c = new_complex(0, 0);
	mlx->julia->image.im = new_image(mlx, &(mlx->julia->image.pim));
	mlx->fractale = JULIA;
	mlx->julia->mode_zoom = 0;
	init_quantum(mlx);
	julia_image(mlx);
}

void			open_julia(t_mlx *mlx)
{
		mlx->julia = ft_malloc(sizeof(*(mlx->julia)));
		init_julia(mlx);
		mlx_hook(mlx->win, 6, 1L < 6, input_julia, mlx);
}

void			init_mandelbrot(t_mlx *mlx)
{
		mlx->mandelbrot->cmin = new_complex(-2.05, -1.4);
		mlx->mandelbrot->cmax = new_complex(0.80, 1.4);
		mlx->mandelbrot->image.im = new_image(mlx, &(mlx->mandelbrot->image.pim));
		mlx->fractale = MANDELBROT;
		init_quantum(mlx);
		mandelbrot_image(mlx);
}

void			open_mandelbrot(t_mlx * mlx)
{
		mlx->mandelbrot = ft_malloc(sizeof(*(mlx->mandelbrot)));
		init_mandelbrot(mlx);
}

void			reset_fractole(t_mlx *mlx)
{
	if (mlx->fractale == MANDELBROT)
		init_mandelbrot(mlx);
	if (mlx->fractale == JULIA)
		init_julia(mlx);
}

static	void	read_fractol(t_mlx *mlx, int ac, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
	{
		open_mandelbrot(mlx);
	}
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		mlx->julia = ft_malloc(sizeof(*(mlx->julia)));
		init_julia(mlx);
		mlx_hook(mlx->win, 6, 1L < 6, input_julia, mlx);
	}
	else
		exit_error("arg");
}

static void		init_fractol(t_mlx *mlx, int ac, char **av)
{
	mlx->width = MAX_WIDTH;
	mlx->height = MAX_HEIGHT;
	mlx->iteration = MAX_ITERATION;
	if (ac >= 3)
		mlx->iteration = ft_atoi(av[2]);
	if (ac >= 5)
	{
		mlx->width = ft_atoi(av[3]);
		mlx->height = ft_atoi(av[4]);
	}
	else if (ac >= 4)
	{
		mlx->width= ft_atoi(av[3]);
		mlx->height= ft_atoi(av[3]);
	}
}

t_mlx			*init(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit_error("nb arg");
	m = ft_memalloc(sizeof(*m));
	m->mlx = mlx_init();
	init_fractol(m, ac, av);
	init_order_color(m->order_color);
	if (!((m->win = mlx_new_window(m->mlx,
						m->width, m->height, "mlx 42"))))
		exit_error("init");
	read_fractol(m, ac, av);
	return (m);
}
