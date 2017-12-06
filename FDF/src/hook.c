/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:59:24 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/06 21:00:58 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "stdio.h"

int		key_hook(int keycode, void	*p)
{
	printf("key : %d \n", keycode);
	if (keycode == ECHAP)
	{
		exit (0);
	}
	//exit (0);
	return (0);
}

int		mouse_hook(int b, int x, int y, void *p)
{
	t_mlx *m= (t_mlx*)p;

	printf("bouton : %d, pos x : %d, pos y : %d\n",b, x, y);
	mlx_pixel_put (m->mlx, m->win, x, y, 0x0000FF);
	return (0);
}

int 	loop_hook(void *param)
{
	//printf("humm, %d",b);
	//usleep(500000);
	return (0);
}

int		expose_hook(void *param)
{
	static int	i = 1;

	if (i)
		affiche(param);
	i = 0;
	return (0);
}
