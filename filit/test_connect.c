/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 08:25:31 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/21 13:41:31 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	point_connect(t_point p1, t_point p2)
{
	if (ft_abs(p1.x - p2.x) == 1 && ft_abs(p1.y - p2.y) == 0)
		return (1);
	if (ft_abs(p1.x - p2.x) == 0 && ft_abs(p1.y - p2.y) == 1)
		return (1);
	return (0);
}

static int	nb_connect(t_point p1, t_point p2, t_point p3, t_point p4)
{
	t_point	p[4];
	int		i;
	int		j;
	int		cmp;

	p[0] = p1;
	p[1] = p2;
	p[2] = p3;
	p[3] = p4;
	i = 0;
	j = 0;
	cmp = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != j && point_connect(p[i], p[j]))
				cmp++;
			j++;
		}
		i++;
	}
	return (cmp);
}

static int	connect(t_tetri t)
{
	t_point	p0;
	int		cmp;

	p0.x = 0;
	p0.y = 0;
	if ((cmp = nb_connect(p0, t.two, t.three, t.four)) >= 6)
	{
		return (1);
	}
	return (0);
}

int			tetri_connect(t_tetri *tetri_list)
{
	while (tetri_list)
	{
		if (!connect(*tetri_list))
			return (0);
		tetri_list = tetri_list->next;
	}
	return (1);
}
