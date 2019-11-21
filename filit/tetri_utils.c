/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:28:01 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/21 14:02:27 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	insert_if_possible(t_map *m, t_tetri *tetri,
		int y, int x)
{
	if (m->map[x][y] != '.')
		return (0);
	if (x + tetri->two.x >= m->size || y + tetri->two.y >= m->size ||
			m->map[x + tetri->two.x][y + tetri->two.y] != '.')
		return (0);
	if (x + tetri->three.x >= m->size || y + tetri->three.y >= m->size ||
			m->map[x + tetri->three.x][y + tetri->three.y] != '.')
		return (0);
	if (x + tetri->four.x >= m->size || y + tetri->four.y >= m->size ||
			m->map[x + tetri->four.x][y + tetri->four.y] != '.')
		return (0);
	m->map[x][y] = tetri->letter;
	m->map[x + tetri->two.x][y + tetri->two.y] = tetri->letter;
	m->map[x + tetri->three.x][y + tetri->three.y] = tetri->letter;
	m->map[x + tetri->four.x][y + tetri->four.y] = tetri->letter;
	return (1);
}

unsigned int		insert_tetri(t_map *map, t_tetri *t, int *x, int *y)
{
	while (*y < map->size)
	{
		while (*x < map->size)
		{
			if (insert_if_possible(map, t, *x, *y))
				return (1);
			(*x)++;
		}
		(*y)++;
		*x = 0;
	}
	return (0);
}

void				remove_tetri(t_map *m, t_tetri *tetri, int y, int x)
{
	m->map[x][y] = '.';
	m->map[x + tetri->two.x][y + tetri->two.y] = '.';
	m->map[x + tetri->three.x][y + tetri->three.y] = '.';
	m->map[x + tetri->four.x][y + tetri->four.y] = '.';
}
