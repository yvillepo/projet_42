/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:51:26 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:25:13 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_ray(t_mlx *mlx, t_vect *dir, double x, double y)
{
	t_vect	uv;
	t_vect	*i;
	t_vect	*j;
	t_vect	*k;

	uv.x = (mlx->h / 2) - mlx->pitch * x;
	uv.y = (mlx->h / 2) - mlx->pitch * y;
	k = mlx->camera_dir;
	v_unit(k);
	j = new_vect(0, 1, 0);
	i = v_cross(k, j);
	v_unit(i);
	free(j);
	j = v_cross(i, k);
	dir->x = uv.x * i->x + uv.y * j->x + k->x;
	dir->y = uv.x * i->y + uv.y * j->y + k->y;
	dir->z = uv.x * i->z + uv.y * j->z + k->z;
	free(i);
	free(j);
	v_unit(dir);
}

void		read_camera(t_mlx *mlx, int fd)
{
	mlx->camera_pos = read_vect(fd);
	mlx->camera_dir = read_vect(fd);
	v_unit(mlx->camera_dir);
}

void		read_light(t_mlx *mlx, int fd)
{
	mlx->light = read_vect(fd);
}
