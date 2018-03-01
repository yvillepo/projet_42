/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:10:32 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/01 01:15:54 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_mlx		*mlx;

	mlx = init(ac, av);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	while (mlx->object)
	{
		printf("%d\n",((t_object*)(mlx->object->content))->type);
		printf("%f\n",((t_sphere*)(((t_object*)(mlx->object->content))->form))->rayon);
		printf("%x\n",((t_object*)(mlx->object->content))->color.color);
		mlx->object = mlx->object->next;
	}
	trace_ray(mlx, mlx->object);
	mlx_loop(mlx);
	return (0);
}
