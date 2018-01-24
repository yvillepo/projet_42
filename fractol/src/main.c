/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 10:51:22 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_mlx		*mlx;

	mlx = init(ac, av);
	mlx->c1 = new_complex(-2.05, -1.4);
	mlx->c2 = new_complex(0.80, 1.4);
	centre(mlx);
	mandelbrot_image(mlx);
	//mlx_hook(mlx->win, 6, 1L < 6, input_julia, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
