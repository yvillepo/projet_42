/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:42:44 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 03:02:07 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	init_mlx(t_mlx *m)
{
	if (!((m->mlx = mlx_init())
				&& (m->win = mlx_new_window(m->mlx,
						m->width, m->height, "mlx 42"))))
		exit_error("init");
	printf("fin init mlx\n");
}

void	init_fractol(t_mlx *mlx, int ac, char **av)
{
	printf("je suis con ou quoi %d %s \n%d\n",ac,av[2],ft_atoi(av[2]));
	if (ac >= 3)
	{
		printf("%d\n",ft_atoi(av[2]));
		mlx->iteration = ft_atoi(av[2]);
	}
	else
		mlx->iteration = ITERATION_MAX;
	if (ac == 4)
	{
		mlx->width = ft_atoi(av[3]);
		mlx->height = ft_atoi(av[3]);
	}
	else if (ac >= 5)
	{
		mlx->width = ft_atoi(av[4]);
		mlx->height = ft_atoi(av[4]);
	}
	else
	{
		mlx->width = DEFAULT_WIDTH;
		mlx->height = DEFAULT_HEIGHT;
	}
}

t_mlx	*init(int ac, char **av)
{
	t_mlx	*m;

	if (ac < 2)
		exit_error("nb arg");
	m = ft_memalloc(sizeof(*m));
	init_fractol(m, ac, av);
	init_mlx(m);
	m->image.im = new_image(m, &(m->image.pim));
	return (m);
}
