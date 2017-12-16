/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/16 01:43:19 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"


int	main(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit_error("nb arg");
	init(&m, ac, av);
	read_input(av[1], m);
	mlx_key_hook(m->win, key_hook, m);
//	mlx_mouse_hook(m->win, mouse_hook, (void*)&m);
	mlx_expose_hook(m->win, expose_hook, m);
//	mlx_loop_hook(m->win, loop_hook, 0);
	mlx_loop(m->mlx);
	return (0);
}
