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
/*
static void	init_fractol(t_mlx *mlx)
{
	mlx->width = ;
	mlx->height = ;
	mlx->iteration = ;
}
*/
t_mlx		*init(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit_error("nb arg");
	m = ft_memalloc(sizeof(*m));
	if (!((m->mlx = mlx_init())
				&& (m->win = mlx_new_window(m->mlx,
						MAX_WIDTH, MAX_HEIGHT, "mlx 42"))))
		exit_error("init");
	m->image.im = new_image(m, &(m->image.pim));
	return (m);
}
