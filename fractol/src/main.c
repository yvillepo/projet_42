/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/28 15:23:17 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_controls(void)
{
	ft_putstr("\
_____________________________________________________________\n\
ARGUMENT:\n\
	Arg1            = Nom fractal (mandelbrot, julia, burning)\n\
	Arg2 (optionel) = Nombre itterations\n\
	Arg3 (optionel) = Taille fenaitre (en pixel)\n\
\n\
CONTROLS:\n\
Translation:\n\
	touches flèches\n\
\n\
Zoom:\n\
	IN  : Molette ou clic droit\n\
	OUT : Molette ou clic gauche\n\
\n\
Fractal:\n\
	Afficher la fractal suivante                  : N ou D\n\
	Afficher la fractal precedente                : A\n\
	Entrer/Quiter mode zoom (julia)               : return\n\
	Changer les couleurs                          : ESPACE\n\
	Augmenter precision (iteration max) 		  : X\n\
	Diminuer precision (iteration max)			  : W\n\
	Reset fractal                                 : R\n\
_______________________________________________________________\n");
}

int		main(int ac, char **av)
{
	t_mlx		*mlx;

	mlx = init(ac, av);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	display_controls();
	mlx_loop(mlx->mlx);
	return (0);
}
