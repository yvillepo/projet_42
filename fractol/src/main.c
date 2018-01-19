/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 02:25:35 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_mlx		*mlx;

	mlx = init(ac, av);
	mlx->c1 = new_complex(-2.25, -1.5);
	mlx->c2 = new_complex(0.75, 1.5);
	centre(mlx);
	mandelbrot_image(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx);
	return (0);
}
