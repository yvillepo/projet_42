/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:42:57 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/21 19:08:10 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			v_is_unit(t_vect *v)
{
	if (v_l(v) == 1)
		return (1);
	return (0);
}

t_vect		*find_octo(t_vect *v)
{
	t_vect *res;

	res = 0;
	if(v->x != 0)
		res  = new_vect(-(v->y + v->z) / v->x, 1 , 1);
	else if(v->y != 0)
		res = new_vect(1, -(v->x + v->z) / v->y ,1);
	else if(v->z != 0)
		res = new_vect(1 , 1, -(v->x + v->y) / v->z);
	else
		exit_error("vecteur dir NULL");	
	v_unit(res);
	return (res);
}

void		v_print(t_vect *v)
{
	printf ("v : %f %f %f\n",v->x, v->y, v->z);
}

int		is_between(t_vect *va, t_vect *vb, t_vect *vm)
{
	t_line line;
	t_vect *um; 
	double	t;

	line.dir = new_vect(vb->x - va->x, vb->y - va->y, vb->z - va->z);
	line.origin = va;
	um = new_vect(vm->x - va->x, vm->y - va->y, vm->z - va->z);
	t = is_coplanar(line.dir, um);
	t = ft_abs_double(t);
	if (t == 0)
		return (-1);
	if (t > 1.0 || t < 0.0)
		return (0);
	return (1);
}

double		is_coplanar(t_vect *va, t_vect *vb)
{
	double	p;

	p = vb->x / va->x;
	if (va->y * p == vb->y && va->z * p == vb->z)
		return (p);
	return (0.0);
}

void	print_vect(char *s, t_vect *v)
{
	printf("%s = %f %f %f\n",s, v->x, v->y, v->z);
}

void	print_plane(t_plane *plane)
{
	printf("plane :\nnomrmal : %f %f %f\nd : %f\n", plane->normal->x, plane->normal->y,
			plane->normal->z, plane->d);
}

t_vect	*p_normal(t_vect *u, t_vect *v)
{
	t_vect	*res;

	res = ft_malloc(sizeof(*res));
	res->x = 1;
	res->y = res->x * (u->x - v->x * u->z / v->z) / (v->y * u->z / v->z - u->y); 
	res->z = -(res->x * v->x + res->y * v->y) / v->z;
	v_unit(res);	
	return (res);
}

void			print_camera(t_mlx *mlx)
{
	printf("pos camera %f %f %f\n",mlx->camera_pos->x,
			mlx->camera_pos->y, mlx->camera_pos->z);
	printf("dir camera %f %f %f\n",mlx->camera_dir->x,
			mlx->camera_dir->y, mlx->camera_dir->z);
}

void		print_object(t_mlx *mlx)
{
	t_object	*object;
	t_list		*obj;
	int			i = 0;

	obj = mlx->object; 
	print_camera(mlx);
	while (obj)
	{
		object = obj->content; 
		if (object->type == SPHERE)
			print_sphere(object->form);
		if (object->type == PLANE)
			print_plane(object->form);
		if (object->type == CYL)
			print_cyl(object->form);
		if (object->type == CONE)
			print_cone(object->form);
		printf("color : %x\n\n", object->color.color);
		obj = obj->next;
		i++;
	}
	printf("nb obj = %d\n",i);
}

void		print_sphere(t_sphere *sphere)
{
	printf("sphere :\ncentre : %f %f %f\nR: %f\n", sphere->centre->x,
			sphere->centre->y, sphere->centre->z, sphere->rayon);
}

void			print_cyl(t_cyl *cyl)
{
	printf("cyl :\ndir : %f %f %f\npositon : %f %f %f\nR = %f\n",
			cyl->dir->x, cyl->dir->y,
			cyl->dir->z, cyl->pos->x, cyl->pos->y, cyl->pos->z, cyl->r);
}
