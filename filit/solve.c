/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:14:42 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/21 14:06:19 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_map	*solve_map(t_map *map, t_tetri *tetri_list)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (tetri_list == NULL)
		return (map);
	while (insert_tetri(map, tetri_list, &x, &y) && y < map->size)
	{
		if (solve_map(map, tetri_list->next))
			return (map);
		else
		{
			remove_tetri(map, tetri_list, x, y);
			x++;
			if (x >= map->size)
			{
				x = 0;
				y++;
			}
		}
	}
	return (0);
}

t_map			*solve(t_tetri *tetri_list, unsigned int nb_tetri)
{
	t_map	*m;
	int		m_size;

	m = create_map_min(nb_tetri);
	m_size = m->size;
	while (!(m = solve_map(m, tetri_list)))
	{
		m = map_new(++m_size);
	}
	return (m);
}
