/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2018/02/09 17:03:42 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				key_hook(int keycode, void *p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)(p);
	if (keycode == ECHAP)
		exit(0);
	return (0);
}

int				mouse_hook(int button, int x, int y, void *param)
{
	t_point		p;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	p.x = x;
	p.y = y;
	return (0);
}
