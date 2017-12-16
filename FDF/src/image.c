/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:56:18 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/16 01:36:22 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdio.h>

unsigned int	*new_image(void *mlx, void **image)
{
	int a;
	int	b;
	int c;

	*image = mlx_new_image(mlx, W, L);
	return ((unsigned int*) mlx_get_data_addr(*image, &a, &b, &c));
}

void			fill_pixel(unsigned int *image,int x, int y, unsigned int color)
{
	if (x >= W || y >= L || x <= 0 || y <= 0)
	{
		printf("point %d, %d pas afficher\n",x,y);
		return ;
	}
	image[x + y * W] = color;
}

void			clear_im(unsigned int *im)
{
	ft_bzero(im, L * W * sizeof(*im)); 
}	

t_point3D	*scale(t_mlx *mlx)
{
	t_point3D 	*p;
	t_point3D 	*new_p;
	t_point3D	*ret;
	int			nbpoint;

	p = mlx->p3D;
	nbpoint = mlx->nbpoint;
	new_p = ft_memalloc(sizeof(*new_p) * mlx->nbpoint);
	ret = new_p;
	while (nbpoint--)
	{
		new_p->x = (p->x * mlx->scale) + W / 2;
		new_p->y = (p->y * mlx->scale) + L / 2;
		p++;
		new_p++;
	}
	return (ret);
}

void	affiche(t_mlx *mlx)
{
	t_point3D	*p3D;
	int			nbpoint;
	t_point3D	*pixel;

	p3D = mlx->p3D;
	nbpoint = mlx->nbpoint;
	pixel = scale(mlx);
	trace_line(mlx->image.im, mlx, pixel);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image.pim, 0, 0);
	clear_im(mlx->image.im);
	free(pixel);
}
