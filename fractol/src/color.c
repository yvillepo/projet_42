/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:56:49 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/19 10:53:47 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

unsigned int		color(float percent)
{
	return (percent *0xFFFFFF);
}

unsigned int		color1(double percent)
{
	t_color color;

	color.color = 0;
	if (percent < 0.33333)
	{
		color.rgb[2] = (unsigned char)(percent * 3 * 0xFF);
	}
	else
	{
		color.rgb[2] = 0xFF;
		percent = percent - 0.33333;
		if (percent < 0.33333)
			color.rgb[1] = (unsigned char)(percent * 3 * 0xFF);
		else
		{
			color.rgb[1] = 0xFF;
			percent = percent - 0.33333;
			color.rgb[0] = (unsigned char)(percent * 3 * 0xFF);
		}
	}
	return (color.color);
}
