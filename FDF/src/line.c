/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:19:36 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 10:53:23 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		trace_vertical(t_mlx *mlx, t_point3d *p1,
		t_point3d *p2, unsigned int color)
{
	int			x;
	int			y;

	x = p1->x;
	if ((int)p1->y < (int)p2->y)
	{
		y = p1->y;
		while (y <= (int)p2->y)
			fill_pixel(mlx, x, y++, color);
	}
	else
	{
		y = p2->y;
		while (y <= (int)p1->y)
			fill_pixel(mlx, x, y++, color);
	}
}

static void		trace_x(t_mlx *mlx, t_point3d *p,
		double a, unsigned int color)
{
	int				i;
	int				x_max;
	int				x;
	int				y;

	if (p[0].x < p[1].x)
	{
		x = p[0].x;
		y = p[0].y;
		x_max = p[1].x;
	}
	else
	{
		x = p[1].x;
		y = p[1].y;
		x_max = p[0].x;
	}
	i = 0;
	while (i < x_max - x)
	{
		fill_pixel(mlx, x + i, y + a * i, color);
		i++;
	}
}

static void		trace_y(t_mlx *mlx, t_point3d *p,
		double a, unsigned int color)
{
	int				i;
	int				y_max;
	int				x;
	int				y;

	a = 1.0 / a;
	if (p[0].y < p[1].y)
	{
		x = p[0].x;
		y = p[0].y;
		y_max = p[1].y;
	}
	else
	{
		x = p[1].x;
		y = p[1].y;
		y_max = p[0].y;
	}
	i = 0;
	while (i < y_max - y)
	{
		fill_pixel(mlx, x + a * i, y + i, color);
		i++;
	}
}

void			trace_one_line(t_mlx *mlx, t_point3d *p1, t_point3d *p2)
{
	t_point			a;
	unsigned int	color;
	t_point3d		p[2];

	p[0] = *p1;
	p[1] = *p2;
	if (p1->c.color >= p2->c.color)
		color = p1->c.color;
	else
		color = p2->c.color;
	if ((int)p1->x == (int)p2->x)
	{
		trace_vertical(mlx, p1, p2, color);
		return ;
	}
	a = (p2->y - p1->y) / (p2->x - p1->x);
	if ((a <= 1 && a >= -1) || a == 0)
		trace_x(mlx, p, a, color);
	else
		trace_y(mlx, p, a, color);
}

void			trace_line(t_mlx *mlx, t_point3d *p)
{
	int		x;
	int		y;
	int		width;
	int		height;

	width = mlx->width;
	height = mlx->height;
	x = 0;
	y = 0;
	fill_pixel(mlx, p->x, p->y, p->c.color);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x < width - 1)
				trace_one_line(mlx, &p[x + width * y], &p[x + 1 + width * y]);
			if (y < height - 1)
				trace_one_line(mlx, &p[x + width * y], &p[x + width * (y + 1)]);
			x++;
		}
		y++;
	}
}
