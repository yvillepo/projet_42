/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:16:18 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 13:17:11 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*new_vect(double x, double y, double z)
{
	t_vect	*new;

	new = ft_memalloc(sizeof(*new));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_color	mult_color(t_color color, double mult)
{
	if (mult < 0)
		mult = 0;
	if (mult > 1)
		mult = 1;
	if (mult == 0)
		printf ("noir\n");
	color.rgb[0] *= mult;
	color.rgb[1] *= mult;
	color.rgb[2] *= mult;
	return (color);
}

void	free_tab(char **tabstr)
{
	if (!tabstr)
		return ;
	while (*tabstr)
	{
		if (*tabstr)
			free(*tabstr);
		tabstr++;
	}
	*tabstr = NULL;
}

int		len_tabstr(char **tabstr)
{
	int	i;

	i = 0;
	while (*tabstr)
	{
		tabstr++;
		i++;
	}
	return (i);
}

void	free_tabstr(char ***tabstr)
{
	free_tab(*tabstr);
	if (*tabstr)
		free(*tabstr);
}

double	calc_height_screen(t_mlx *mlx)
{
	return (tan(mlx->fov / 2) * 2);
}
