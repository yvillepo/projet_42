/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/16 01:41:37 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static double deg_to_rad(double a)
{
	double ret;

	ret = a * PI / 180;
	return (ret);
}

void	init(t_mlx **mlx, int ac, char **av)
{
	t_mlx	*m;

	*mlx = ft_memalloc(sizeof(**mlx));
	m = *mlx;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 2500, 1300, "mlx 42");
	m->image.im = new_image(m->mlx, &(m->image.pim));
	m->scale = 32;
	m->angle = deg_to_rad(22);
	if (ac >= 3)
		m->scale = ft_atoi(av[2]);	
	if (ac >= 4)
		m->scale = deg_to_rad(atoi(av[3]));
}
