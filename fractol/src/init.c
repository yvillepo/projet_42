/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/17 10:57:09 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	init_mlx(t_mlx **mlx)
{
	t_mlx	*m;

	*mlx = ft_memalloc(sizeof(*m));
	m = *mlx;
	if (!((m->mlx = mlx_init())
				&& (m->win = mlx_new_window(m->mlx,
						MAX_WIDTH, MAX_HEIGHT, "mlx 42"))))
		exit_error("init");
	m->image.im = new_image(m, &(m->image.pim));
}

t_mlx	*init(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit_error("nb arg");
	m = ft_memalloc(sizeof(*m));
	init_mlx(&m);
//	m->width = DEFAULT_WIDTH;
//	m->height = DEFAULT_HEIGHT;
	return (m);
}
