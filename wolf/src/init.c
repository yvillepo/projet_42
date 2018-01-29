/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 10:46:32 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

t_mlx			*init(void)
{
	t_mlx	*mlx;

	mlx = ft_memalloc(sizeof(*mlx));
	mlx->texture = 1;
	mlx->map = ft_malloc(sizeof(**(mlx->map)) * WIDTH);
	*(mlx->map) = ft_malloc(sizeof(*(mlx->map)) * HEIGHT);
	mlx->mlx = mlx_init();
	if (!((mlx->win = mlx_new_window(mlx->mlx,
						WIDTH, HEIGHT, "mlx 42"))))
		exit_error("init");
	mlx->image.im = new_image(mlx, &(mlx->image.pim));
	return (mlx);
}
