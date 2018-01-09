/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 11:07:53 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	display_controls(void)
{
	ft_putstr("\
____________________________\n\
ARGUMENT:\n\
	arg1 = fichier fdf\n\
	arg2 = angle (optionnel) PI / 5 par defaut\n\
\n\
CONTROLS:\n\
Translation:\n\
	Y: Key: W, S\n\
	X: Key: A, D\n\
\n\
Rotation:\n\
	X: Keypad: LEFT, RIGHT\n\
	Y: Keypad: 1, 2\n\
	Z: Keypad: UP, DOWN\n\
\n\
Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -\n\
____________________________\n\
");
}

int		main(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit_error("nb arg");
	m = ft_memalloc(sizeof(*m));
	read_input(av[1], m);
	init(&m, ac, av);
	mlx_key_hook(m->win, key_hook, &m);
	rotate_x(m, PI / 5);
	rotate_z(m, PI / 5);
	affiche(m);
	display_controls();
	mlx_loop(m->mlx);
	free_mlx(&m);
	return (0);
}
