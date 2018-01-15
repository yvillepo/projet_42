/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/16 00:28:04 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int		key_hook(int keycode, void **p)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)(*p);
	/*else if (keycode == PLUS)
		zoom(mlx, 1.10);
	else if (keycode == MOIN)
		zoom(mlx, 0.90);
		*/
	if (keycode == ECHAP)
	{
		mlx_free(*p);
		exit(0);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_point		*p;
	t_mlx		*mlx;
	
	mlx = (t_mlx*)param;
//	printf("button mouse %d", button);
	p = new_point(x, y);
	zoom(mlx, 1000, p); 
	return (0);
}
