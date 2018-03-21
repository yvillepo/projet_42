/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:45:22 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/21 18:34:23 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac < 2)
		exit_error("arg");
	mlx = init(ac, av);
	trace_ray(mlx, mlx->object);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
