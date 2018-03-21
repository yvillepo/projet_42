/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:51:26 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 13:06:13 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	read_camera(t_mlx *mlx, int fd)
{
	mlx->camera_pos = read_vect(fd);
	mlx->camera_dir = read_vect(fd);
	v_unit(mlx->camera_dir);
}

void	read_light(t_mlx *mlx, int fd)
{
	mlx->light = read_vect(fd);
}
