/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/13 00:30:48 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_mlx		*mlx;
	t_complex	*cmin;
	t_complex	*cmax;


	mlx = init(ac, av);
	printf("la ca va \n");
	cmin = new_complex(-2.5, -1.6);
	cmax = new_complex(1, 1.6);
	printf ("%f, ", cmin->r);
	mandelbrot_image(mlx, cmin, cmax);
	mlx_key_hook(mlx->win, key_hook, &mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
