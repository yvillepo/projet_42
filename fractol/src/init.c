/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 10:46:32 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_order_color(int order_color[3])
{
	order_color[0] = 2;
	order_color[1] = 1;
	order_color[2] = 0;
}

static void		init_fractol(t_mlx *mlx, int ac, char **av)
{
	mlx->width = DEFAULT_HEIGHT;
	mlx->height = DEFAULT_HEIGHT;
	mlx->iteration = MAX_ITERATION;
	if (ac >= 3)
	{
		if (ft_atoi(av[2]) > 10 && ft_atoi(av[2]) < 10000)
			mlx->iteration = ft_atoi(av[2]);
	}
	if (ac >= 4)
	{
		if (ft_atoi(av[3]) <= 1300 && ft_atoi(av[3]) > 100)
		{
			mlx->width = ft_atoi(av[3]);
			mlx->height = ft_atoi(av[3]);
		}
		else if (ft_atoi(av[3]) > 1300)
		{
			mlx->width = 1300;
			mlx->height = 1300;
		}
	}
	mlx->burning = NULL;
	mlx->julia = NULL;
	mlx->mandelbrot = NULL;
}

t_mlx			*init(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2 || (ft_strcmp(av[1], "mandelbrot") &&
		ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "burning")))
	{
		ft_putendl("USAGE : /fractol \"mandelbrot\", \"julia\", \"burning\"\
[ [ ITERATION MAX ] [ TAILLE FENAITRE ] ]");
		exit(0);
	}
	m = ft_memalloc(sizeof(*m));
	m->mlx = mlx_init();
	init_fractol(m, ac, av);
	init_order_color(m->order_color);
	if (!((m->win = mlx_new_window(m->mlx,
						m->width, m->height, "mlx 42"))))
		exit_error("init");
	read_fractol(m, av);
	return (m);
}
