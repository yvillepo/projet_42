/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 00:38:11 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 09:46:12 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

unsigned int	*new_image(t_mlx *mlx, void **image)
{
	int a;
	int	b;
	int c;

	*image = mlx_new_image(mlx->mlx, mlx->width_window, mlx->height_window);
	return ((unsigned int*)mlx_get_data_addr(*image, &a, &b, &c));
}

void			fill_pixel(t_mlx *mlx, int x1,
		int y1, unsigned int color)
{
	int		x;
	int		y;

	x = x1 + mlx->centre.x;
	y = y1 + mlx->centre.y;
	if (x >= mlx->width_window || y >= mlx->height_window || x <= 0 || y <= 0)
		return ;
	mlx->image.im[x + y * mlx->width_window] = color;
}

void			clear_im(t_mlx *mlx, unsigned int *im)
{
	ft_bzero(im, mlx->height_window * mlx->width_window * sizeof(*im));
}

void			affiche(t_mlx *mlx)
{
	int			nbpoint;

	nbpoint = mlx->nbpoint;
	trace_line(mlx, mlx->p);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.pim, 0, 0);
	clear_im(mlx, mlx->image.im);
}
