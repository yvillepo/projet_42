/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 10:52:58 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

double	deg_to_rad(double a)
{
	double ret;

	ret = a * PI / 180.0;
	return (ret);
}

void	init(t_mlx **mlx, int ac, char **av)
{
	t_mlx	*m;

	m = *mlx;
	if (m->nbpoint == 1)
	{
		m->width_window = SCALE_MAX * m->p->z + 100;
		m->height_window = SCALE_MAX * m->p->z + 100;
	}
	if (!((m->mlx = mlx_init())
				&& (m->win = mlx_new_window(m->mlx,
						m->width_window, m->height_window, "mlx 42"))))
		exit_error("init");
	m->image.im = new_image(m, &(m->image.pim));
	m->angle = PI / 10;
	if (ac >= 3)
		m->angle = deg_to_rad(atoi(av[2]));
	m->centre.x = m->width_window / 2;
	m->centre.y = m->height_window / 2;
}
