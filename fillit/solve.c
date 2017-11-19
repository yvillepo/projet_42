/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:14:42 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/19 17:44:34 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static	unsigned int	map_min(unsigned int nb_tetri)
{
	unsigned int	size_map;

	size_map = 0;
	nb_tetri = nb_tetri * 4;
	while (size_map * size_map < nb_tetri)
		size_map++;;
	return(size_map);
}

static t_map	*solve_map(t_map *map, t_tetri *ltetri)
{
	int     x;
	int     y;

	x = 0;
	y = 0;
	if (ltetri == NULL)
		return(map);
	while (insert_tetri(map, ltetri, &x, &y) && y < map->size)
	{
		if(solve_map(map, ltetri->next))
			return (map);
		else
		{
			retire_tetri(map, ltetri, x, y);
			x++;
		}
	}
	free_map(map);
	return (0);
}

t_map	*solve(t_tetri *ltetri, unsigned int nb_tetri)
{
	t_map			*m;
	unsigned int	m_size;

	m_size = map_min(nb_tetri);
	m = map_new(nb_tetri);
	ft_putchar('\n');
	while (!(m = solve_map(m, ltetri)))
	{
		free_map(m);
		map_new(++m_size);
	}
	return (m);
}
