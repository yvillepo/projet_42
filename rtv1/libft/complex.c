/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:44:33 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/26 09:45:50 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		add_complex(t_complex *z1, t_complex *z2)
{
	t_complex	res;

	res.r = z1->r + z2->r;
	res.i = z1->i + z2->i;
	return (res);
}

t_complex		mult_complex(t_complex *z1, t_complex *z2)
{
	t_complex	res;

	res.r = z1->r * z2->r - z1->i * z2->i;
	res.i = z1->r * z2->i + z2->r * z1->i;
	return (res);
}

double			mod2(t_complex *z1)
{
	return (z1->r * z1->r + z1->i * z1->i);
}

t_complex		*new_complex(double r, double i)
{
	t_complex	*z;

	z = ft_malloc(sizeof(*z));
	z->r = r;
	z->i = i;
	return (z);
}
