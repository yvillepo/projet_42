/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:38:11 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/16 00:19:01 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

unsigned int	*new_image(t_mlx *mlx, void **image)
{
	int a;
	int	b;
	int c;

	*image = mlx_new_image(mlx->mlx, MAX_WIDTH, MAX_HEIGHT);
	return ((unsigned int*)mlx_get_data_addr(*image, &a, &b, &c));
}

void			fill_pixel(t_mlx *mlx, int x1,
		int y1, unsigned int color)
{
	int		x;
	int		y;

	x = x1 ;
	y = y1 ;
	if (x >= MAX_WIDTH || y >= MAX_HEIGHT || x <= 0 || y <= 0)
		return ;
	mlx->image.im[x + y * MAX_WIDTH] = color;
}

void			clear_im(unsigned int *im)
{
	ft_bzero(im, MAX_HEIGHT * MAX_WIDTH * sizeof(*im));
}

void			affiche(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.pim, 0, 0);
}
