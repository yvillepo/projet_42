/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:25:02 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/24 08:44:24 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_point		*new_point(int x, int y)
{
	t_point		*p;

	p = ft_malloc(sizeof(*p));
	p->x = x;
	p->y = y;
	return (p);
}

/*void	 affiche_mlx(t_mlx *mlx)
{
	printf("mlx		:	c1 %f %f, c2 %f %f, quantum %f\n",mlx->c1->r, mlx->c1->i,
			mlx->c2->r, mlx->c2->i, mlx->quantum);
}*/

void	mlx_free(t_mlx **m)
{
	t_mlx	*mlx;
/*
	mlx = *m;
	free(mlx->c1);
	free(mlx->c2);
	if (mlx->image.pim)
		mlx_destroy_image(mlx, mlx->image.pim);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
	free(mlx);
	*/
}
