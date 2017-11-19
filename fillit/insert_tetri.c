/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:28:01 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/19 17:51:17 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	insert_tetri_0(t_map *m, t_tetri *tetri)
{
	m->map[0][0] = tetri->letter;
	m->map[tetri->two.x][tetri->two.y] = tetri->letter;
	m->map[tetri->three.x][tetri->three.y] = tetri->letter;
	m->map[tetri->four.x][tetri->four.y] = tetri->letter;
	return (1);
}

void				affiche(t_tetri *tetri)
{
	t_map *m;

	m = map_new(4);
    insert_tetri_0(m, tetri);
	print_map(m);
	ft_putchar('\n');
	free_map(m);
}

static unsigned int	insert_tetri_pos(t_map *m, t_tetri *tetri,unsigned int x, unsigned int y)
{
	if(m->map[x][y] != '.')
		return (0);
	if(x + tetri->two.x < m->size && y + tetri->two.y < m->size &&
			m->map[x + tetri->two.x][y + tetri->two.y] != '.')
		return (0);
	if(x + tetri->three.x < m->size && y + tetri->three.y < m->size &&
			m->map[x + tetri->three.x][y + tetri->three.y] != '.')
		return (0);
	if(x + tetri->four.x < m->size && y + tetri->four.y < m->size &&
			m->map[x + tetri->four.x][y + tetri->four.y] != '.')
		return (0);
	m->map[x][y] = tetri->letter;
	m->map[x+tetri->two.x][y+tetri->two.y] = tetri->letter;
	m->map[x+tetri->three.x][y+tetri->three.y] = tetri->letter;
	m->map[x+tetri->four.x][y+tetri->four.y] = tetri->letter;
	ft_putstr("map apre insertion tetri : \n");
	affiche(tetri);
	print_map(m);
	ft_putchar('\n');
	return (1);
}

unsigned int		insert_tetri(t_map *map, t_tetri *tetri, int *x, int *y)
{
	if (*x >= map->size)
	{
		*x = 0;
		(*y)++;
	}
	while (*y < map->size)
	{	
		while (*x < map->size)
		{
			if(insert_tetri_pos(map, tetri, *x, *y))
				return (1);
			(*x)++;
		}
		(*y)++;
		*x = 0;
	}
	return (0);
}

void			retire_tetri(t_map *m, t_tetri *tetri, int x, int y)
{
	m->map[x][y] = '.';
	m->map[x+tetri->two.x][y+tetri->two.y] = '.';
	m->map[x+tetri->three.x][y+tetri->three.y] = '.';
	m->map[x+tetri->four.x][y+tetri->four.y] = '.';
}
