/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:38:52 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:29:41 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	shadow(t_list *o, t_line *light)
{
	double		t;
	int			cmp;
	double		res;

	cmp = 0;
	res = 0.30;
	while (o)
	{
		t = intersec_unit(o->content, light);
		if (t < 0.9999999 && t > 0)
			cmp++;
		o = o->next;
	}
	if (cmp == 0)
		return (10);
	return (res / cmp);
}

double			is_shadow(t_mlx *mlx, t_line *cam, double d)
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

static t_vect	*calc_cc(t_object *obj, t_vect *pos, t_line *cam, double t)
{
	t_vect	*tmp;
	t_vect	tmp2;
	t_vect	*tmp3;
	t_vect	*norm;

	tmp3 = NULL;
	tmp = v_sub(pos, ((t_cyl*)obj->form)->pos);
	tmp3 = v_sub(cam->origin, ((t_cyl*)obj->form)->pos);
	tmp2 = unit_scale(v_mult(cam->dir, ((t_cyl*)obj->form)->dir) * t +
			v_mult(((t_cyl*)obj->form)->dir, tmp3),
			((t_cyl*)obj->form)->dir);
	free(tmp3);
	if (obj->type == CONE)
	{
		tmp3 = v_sub(&tmp2, ((t_cone*)obj->form)->pos);
		norm = v_sub(tmp, tmp3);
		free(tmp3);
	}
	else
		norm = v_sub(tmp, &tmp2);
	free(tmp);
	return (norm);
}

static t_vect	*calc_norm(double t, t_line *cam, t_object *obj, t_vect *pos)
{
	t_vect	*norm;

	norm = 0;
	if (obj->type == SPHERE)
		norm = v_sub(pos, ((t_sphere*)obj->form)->centre);
	if (obj->type == PLANE)
		norm = ((t_plane*)obj->form)->normal;
	if (obj->type == CYL || obj->type == CONE)
		norm = calc_cc(obj, pos, cam, t);
	if (norm)
		return (norm);
	else
		exit_error("calc norm");
	return (NULL);
}

double			calc_light(t_mlx *mlx, t_line *cam, t_object *obj, double t)
{
	t_vect		*norm;
	t_vect		*dir_light;
	t_vect		*pos;
	double		percent;
	double		res;

	norm = 0;
	pos = calc_point(cam, t);
	norm = calc_norm(t, cam, obj, pos);
	v_unit(norm);
	dir_light = v_sub(pos, mlx->light);
	v_unit(dir_light);
	percent = is_shadow(mlx, cam, t);
	free(pos);
	if (percent < 10 && mlx->ombre)
		res = percent * ft_absd(v_mult(dir_light, norm));
	else
		res = ft_absd(v_mult(dir_light, norm));
	if (norm && (norm != ((t_plane*)obj->form)->normal))
		free(norm);
	free(dir_light);
	return (res);
}
