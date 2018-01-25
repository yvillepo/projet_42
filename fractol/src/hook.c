/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/25 03:41:10 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int		key_hook(int keycode, void *p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)(p);
	printf ("cle = %d\n",keycode);
	if (keycode >= LEFT || keycode <= UP)
		translation_fractale(mlx, keycode, 0.10);
	if (keycode == ECHAP)
	{
//		mlx_free(&mlx);
		exit(0);
	}
	if (keycode == SPACE)
	{
		change_color(mlx->order_color);
		affiche_fractal(mlx);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_point		*p;
	t_mlx		*mlx;
	
	mlx = (t_mlx*)param;
	p = new_point(x, y);
//	printf ("%d buttom \n", button);
	if (button == 5 || button == 1)
		zoom_fractale(mlx, p, 1); 
	if (button == 4 || button == 2)
		zoom_fractale(mlx, p, 0);
	return (0);
}
