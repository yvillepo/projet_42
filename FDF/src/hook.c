/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 10:59:11 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		key_hook(int keycode, void **p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)(*p);
	if ((keycode >= 123 && keycode <= 126) ||
			keycode == UN || keycode == DEUX)
	{
		rotate_key(mlx, keycode, mlx->angle);
	}
	else if (keycode == PLUS)
		zoom(mlx, 1.10);
	else if (keycode == MOIN)
		zoom(mlx, 0.90);
	else if (keycode == ECHAP)
	{
		free_mlx(*p);
		exit(0);
	}
	else if (keycode == T_A || keycode == T_W ||
			keycode == T_S || keycode == T_D)
	{
		translation(mlx, keycode, 100);
	}
	return (0);
}
