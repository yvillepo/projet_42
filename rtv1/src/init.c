/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/14 01:41:13 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_mlx			*init(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit(0);
	m = ft_memalloc(sizeof(*m));
	m->mlx = mlx_init();
	if (!((m->win = mlx_new_window(m->mlx,
						m->width, m->height, "mlx 42"))))
		exit_error("init");
	m->image.im = new_image(m, &(m->image.pim));
	return (m);
}
