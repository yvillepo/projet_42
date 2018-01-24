/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/13 00:59:45 by yvillepo         ###   ########.fr       */
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

static void		init_fractol(t_mlx *mlx, int ac, char ** av)
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
	init_fractol(m, ac, av);
	init_order_color(m->order_color);
	if (!((m->mlx = mlx_init())
				&& (m->win = mlx_new_window(m->mlx,
						m->width, m->height, "mlx 42"))))
		exit_error("init");
	m->image.im = new_image(m, &(m->image.pim));
	return (m);
}
