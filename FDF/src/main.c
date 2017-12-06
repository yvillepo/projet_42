/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/06 21:01:44 by yvillepo         ###   ########.fr       */
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
	m = ft_memalloc(sizeof(*m));
	printf("gdhf\nhffysfd\n\n\n");
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 2500, 1300, "mlx 42");
	read_input(av[1], m);
	fill_point(&(m->eyes), 0, 0, 0);
	mlx_key_hook(m->win, key_hook, 0);
//	mlx_mouse_hook(m->win, mouse_hook, (void*)&m);
	mlx_expose_hook(m->win, expose_hook, m);
//	mlx_loop_hook(m->win, loop_hook, 0);
	mlx_loop(m->mlx);
	return (0);
}
