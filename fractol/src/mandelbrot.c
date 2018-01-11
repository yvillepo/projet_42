/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/11 20:38:29 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <math.h>

int		is_limited(t_complex *c)
{
	int			i;
	t_complex	*z;

	i = ITERATION_MAX;
	z = new_complex(0, 0);
	while(i--)
	{
		*z = mult_complex(z, z);
		*z = add_complex(z, c);
		if (mod2(z) > 4)
			return (0);
		i--;
	}
	return (1);
}

int		*mandelbrot_image(t_complex *c1, t_complex *c2)
{
	double		dx;
	double		dy;

	dx = c2->r - c1->r;
	dy = c2->i - c1->i;
}
