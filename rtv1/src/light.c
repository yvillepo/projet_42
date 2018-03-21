/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:38:52 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 11:38:54 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		shadow(t_list *o, t_line *light)
{
	double		t;

	while (o)
	{
		t = intersec_unit(o->content, light);
		if (t < 0.9999999 && t > 0)
			return (1);
		o = o->next;
	}
	return (0);
}

int				is_shadow(t_mlx *mlx, t_line *cam, double d)
{
	t_line	light;
	t_vect	*tmp;
	double	res;

	tmp = calc_point(cam, d);
	light.origin = mlx->light;
	light.dir = v_sub(tmp, light.origin);
	free(tmp);
	res = shadow(mlx->object, &light);
	free(light.dir);
	return (res);
}

