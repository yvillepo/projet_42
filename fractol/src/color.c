/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 03:56:49 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/24 05:16:45 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

unsigned char		degrade(double percent, int croissant)
{
	if (croissant == 1)
		return (percent * 0xFF);
	return ((1 - percent) * 0xFF);
}

void				change_color(int tab[3])
{
	static int phase = 0;
	int i = -1;

	while (i++ < 2)
		printf ("%d				\n",tab[i]);
	if (phase)
		ft_swap(tab + 1, tab + 2);
	else
		ft_swap(tab, tab + 1);
	if (phase)
		phase = 0;
	else
		phase = 1;
	i = -1;
	while (i++ < 2)
		printf ("%d				\n",tab[i]);
}

unsigned int		color1(double percent)
{
	t_color color;

	color.color = 0;
	if (percent < 0.33333)
	{
		color.rgb[ROUGE] = (unsigned char)(percent * 3 * 0xFF);
	}
	else
	{
		color.rgb[ROUGE] = 0xFF;
		percent = percent - 0.33333;
		if (percent < 0.33333)
			color.rgb[VERT] = (unsigned char)(percent * 3 * 0xFF);
		else
		{
			color.rgb[VERT] = 0xFF;
			percent = percent - 0.33333;
			color.rgb[BLEU] = (unsigned char)(percent * 3 * 0xFF);
		}
	}
	return (color.color);
}

unsigned int		color2(double percent, int ordre_color[3])
{
	t_color color;

	color.color = 0;
	if (percent < 0.25)
	{
		color.rgb[ordre_color[0]] = 255;
		color.rgb[ordre_color[1]] = degrade(percent * 4, 1);
	}
	else if (percent < 0.50)
	{
		color.rgb[ordre_color[1]] = 255;
		color.rgb[ordre_color[0]] = degrade((percent - 0.25) * 4, 0);
	}
	else if (percent < 0.75)
	{
		color.rgb[ordre_color[1]] = 255;
		color.rgb[ordre_color[2]] = degrade((percent - 0.50) * 4, 1);
	}
	else
	{
		color.rgb[ordre_color[2]] = 255;
		color.rgb[ordre_color[1]] = degrade((percent - 0.75) * 4, 0);
	}
	return (color.color);
}
