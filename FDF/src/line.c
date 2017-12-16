/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:19:36 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/15 22:10:18 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			trace_one_line(unsigned int *image, t_point3D *p1, t_point3D *p2)
{
	double		a;
	double		x;
	int		x_max;
	double		i;
	int		y;
	
	if (p1->x == p2->x)
	{
		x = p1->x;
		if (p1->y < p2->y)
		{
			y = p1->y;
			while (y <= p2->y)
				fill_pixel(image, x, y++, 0xFFFFFF);
		}
		else
		{
			y = p2->y;
			while (y <= p1->y)
				fill_pixel(image, x, y++, 0xFFFFFF);
		}
		return ;
	}
	if (p1->x < p2->x)
	{
		a = (double)(p2->y - p1->y) / (double)(p2->x - p1->x);
		x = p1->x;
		y = p1->y;
		x_max = p2->x;
	}
	else
	{
		a = (double)(p1->y - p2->y) / (double)(p1->x - p2->x);
		x = p2->x;
		y = p2->y;
		x_max = p1->x;
	}
	i = 0;
	while (i < x_max - x)
	{
		fill_pixel(image, x + i, (int)(y + a * i),0xFFFFFF);
		i++;
	}	
}

void		trace_line(unsigned int *image, t_mlx *mlx, t_point3D *p)
{
	int		x;
	int		y;
	int		max_x;
	int		max_y;

	max_x = mlx->max.x;
	max_y = mlx->max.y;
	x = 0;
	y = 0;
	printf("%d %d\n",max_x, max_y);
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (x < max_x - 1)
				trace_one_line(image, &p[x + max_x * y], &p[x + 1 + max_x * y]);
			if (y < max_y - 1)
				trace_one_line(image, &p[x + max_x * y], &p[x + max_x * (y + 1)]);
			x++;
		}
		y++;
	}
}
