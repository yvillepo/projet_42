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

int		shadow(t_object *o, t_line *light, t_vect *dir)
{
	t_vect *tmp;

	tmp = light->dir;
	light->dir = 
	intersec_unit(o->content, line)
}
