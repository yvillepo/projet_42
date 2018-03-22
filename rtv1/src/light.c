/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:38:52 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/21 19:09:45 by yvillepo         ###   ########.fr       */
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

static t_vect	*calc_norm(double t, t_line *cam, t_object *obj, t_vect *pos)
{
	t_vect	*norm;
	t_vect	*tmp;
	t_vect	tmp2;
	t_vect	*tmp3;

	norm = 0;
	if (obj->type == SPHERE)
		norm = v_sub(pos, ((t_sphere*)obj->form)->centre);
	if (obj->type == PLANE)
		norm = ((t_plane*)obj->form)->normal;
	if (obj->type == CYL || obj->type == CONE)
	{
		tmp = v_sub(pos, ((t_cyl*)obj->form)->pos);
		tmp2 = unit_scale(v_mult(cam->dir, ((t_cyl*)obj->form)->dir) * t +
				+ v_mult(((t_cyl*)obj->form)->dir,
					v_sub(cam->origin, ((t_cyl*)obj->form)->pos)),
					((t_cyl*)obj->form)->dir);
		if (obj->type == CONE)
		{
			tmp3= v_sub(&tmp2, ((t_cone*)obj->form)->pos);
			return (v_sub(tmp, tmp3));
		}
		norm = v_sub(tmp, &tmp2);
	}
	
	if (norm)
		return (norm);
	return (cam->dir);
}

double			calc_light(t_mlx *mlx, t_line *cam, t_object *obj, double t)
{
	t_vect	*norm;
	t_vect	*dir_light;
	t_vect	*pos;

	pos = calc_point(cam, t);
	norm = calc_norm(t, cam, obj, pos);
	v_unit(norm);
	dir_light = v_sub(pos, mlx->light);
	v_unit(dir_light);
	return (ft_absd(v_mult(dir_light, norm)));
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
