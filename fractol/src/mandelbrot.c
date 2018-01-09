/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:34:31 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/09 21:09:08 by yvillepo         ###   ########.fr       */
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
