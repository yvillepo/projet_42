/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:32:33 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/21 19:01:19 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		calc_dir(t_mlx *mlx, t_vect *dir, double x, double y)
{
	t_vect	uv;
	t_vect	*i;
	t_vect	*j;
	t_vect	*k;

	uv.x = -(mlx->h / 2) + mlx->pitch * x;
	uv.y = -(mlx->h / 2) + mlx->pitch * y;
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

double			intersec_unit(t_object *obj, t_line *line)
{
	double	t;

	t = 0;
	if (obj->type == SPHERE)
		t = inter_sphere(obj->form, line);
	if (obj->type == PLANE)
		t = inter_plane(obj->form, line);
	if (obj->type == CYL)
		t = inter_cyl(obj->form, line);
	if (obj->type == CONE)
		t = inter_cone(obj->form, line);
	return (t);
}

static t_color	calc(t_mlx *mlx, t_vect *dir, t_list *object)
{
	double			min;
	double			t;
	t_line			line;
	t_object		*obj;

	obj = 0;
	min = 100000000000000000;
	line.origin = mlx->camera_pos;
	line.dir = dir;
	while (object)
	{
		t = intersec_unit(object->content, &line);
		if (t < min && t >= 0)
		{
			obj = (t_object*)object->content;
			min = t;
		}
		object = object->next;
	}
	if (is_shadow(mlx, &line, min))
		return (((t_color)(unsigned int)(0)));
	if (obj)
		return (mult_color(obj->color, 0.10 + calc_light(mlx, &line, obj, min)));
	return (((t_color)(unsigned int)0));
}

t_color			intersec(t_mlx *mlx, int i, int j, t_list *object)
{
	t_vect		dir;
	double		min;

	min = 0;
	calc_dir(mlx, &dir, i, j);
	return (calc(mlx, &dir, object));
}
