/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/16 01:05:52 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

int		key_hook(int keycode, void	*p)
{
	printf("keycode : %d", keycode); 
	if (keycode >= 123 && keycode <=126)
		rotate_key((t_mlx*)p, keycode, 0.785398);
	if (keycode == PLUS)
		zoom(p);
	if (keycode == MOIN)
		dezoom(p);
	if (keycode == ECHAP)
	{
		exit (0);
	}
	return (0);
}
/*
int		mouse_hook(int b, int x, int y, void *p)
{
	t_mlx *m= (t_mlx*)p;

	mlx_pixel_put (m->mlx, m->win, x, y, 0x0000FF);
	return (0);
}
*/
int 	loop_hook(void *param)
{
	(void)param;
	return (0);
}

int		expose_hook(void *param)
{
	affiche(param);
	return (0);
}
