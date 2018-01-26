/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 10:14:09 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, void *p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)(p);
	if (keycode >= LEFT || keycode <= UP)
		translation_fractale(mlx, keycode, 0.10);
	if (keycode == ECHAP)
	{
		exit(0);
	}
	if (keycode == SPACE)
	{
		change_color(mlx->order_color);
		affiche_fractal(mlx);
	}
	if (keycode == ENTER && mlx->fractale == JULIA)
		switch_mode(mlx->julia);
	if (keycode == T_R)
		reset_fractole(mlx);
	if (keycode == T_N)
		open_next_fractol(mlx);
	if (keycode == T_X)
		affiche_iteration_max(mlx);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_point		*p;
	t_mlx		*mlx;

	mlx = (t_mlx*)param;
	p = new_point(x, y);
	if (button == 5 || button == 1)
		zoom_fractale(mlx, p, 1);
	if (button == 4 || button == 2)
		zoom_fractale(mlx, p, 0);
	return (0);
}
