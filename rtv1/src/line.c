/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:41:53 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/05 10:52:48 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	calc_point(t_line *line, double t, t_vect *res)
{
	res = new_vect(line->origin->x + line->dir->x * t,
			line->origin->y + line->dir->y * t,
			line->origin->z + line->dir->z * t);
}
