/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:10:43 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 10:51:01 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			input_julia(int x, int y, t_mlx *mlx)
{
	mlx->julia->c->r = x * 2;
	mlx->julia->c->i = y * 2 - 800;
	julia_image(mlx);
}

int			is_limited(t_complex *z0, t_complex *c, int iteration_max)
{
	int			i;
	t_complex	*z;

	i = 0;
	z = z0;
	while(i++ < iteration_max)
	{
		z->r = z->r * z->r - z->i * z->i + c->r;
		z->i = 2 * (z->r * z->i) + c->i;
		if (z->r * z->r + z->i * z->i > 4)
		{
			return (color1(1.0 - (double)i / (iteration_max)));
		}
	}
	return (0);
}

void		julia_image(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	z;

	z.i = mlx->c1->i;
	y = 0;
	while (y < MAX_HEIGHT)
	{
		x = 0;
		z.r = mlx->c1->r;
		while (x < MAX_WIDTH)
		{
			fill_pixel(mlx, x, y, is_limited(c, mlx->c3, ITERATION_MAX));
			z.r += mlx->quantum;
			x++;
		}
		z.i += mlx->quantum;
		y++;
	}
	printf("c = %f %f= c2 = %f %f\n",c.r, c.i, mlx->c2->r, mlx->c2->i);
	affiche(mlx);
}
