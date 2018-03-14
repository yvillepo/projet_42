/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/28 03:57:35 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			calc_pitch(t_mlx *mlx)
{
	mlx->h = calc_height_screen(mlx);
	mlx->pitch = mlx->h / mlx->height;
}

t_mlx			*init(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit(0);
	m = ft_memalloc(sizeof(*m));
	m->mlx = mlx_init();
	m->width = 800;
	m->height = 800;
	m->fov = PI/2;
	if (!((m->win = mlx_new_window(m->mlx,
						m->width, m->height, "mlx 42"))))
		exit_error("init");
	m->object = NULL;
	m->image.im = new_image(m, &(m->image.pim));
	parse(m, av[1]);
	calc_pitch(m);
	return (m);
}
