/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:15 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/20 22:52:10 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_struct(t_tetri *t, int pound_pos, int i, int index_first)
{
	if (pound_pos == 1)
	{
		t->two.x = (i + 1) / 5 - (index_first + 1) / 5;
		t->two.y = (i + 1) % 5 - (index_first + 1) % 5;
	}
	else if (pound_pos == 2)
	{
		t->three.x = (i + 1) / 5 - (index_first + 1) / 5;
		t->three.y = (i + 1) % 5 - (index_first + 1) % 5;
	}
	else if (pound_pos == 3)
	{
		t->four.x = (i + 1) / 5 - (index_first + 1) / 5;
		t->four.y = (i + 1) % 5 - (index_first + 1) % 5;
	}
	return (pound_pos + 1);
}

t_tetri	*get_tetri_pos(char *block, t_tetri *tetri, int i)
{
	int		index_first;
	int		nb_pounds;

	nb_pounds = 0;
	index_first = -1;
	while (block[i] != '\0')
	{
		if (block[i] == '#')
		{
			if (index_first == -1)
			{
				index_first = i;
				nb_pounds = 1;
			}
			if (nb_pounds == 1 && i != index_first)
				nb_pounds = fill_struct(tetri, nb_pounds, i, index_first);
			else if (nb_pounds == 2)
				nb_pounds = fill_struct(tetri, nb_pounds, i, index_first);
			else if (nb_pounds == 3)
				nb_pounds = fill_struct(tetri, nb_pounds, i, index_first);
		}
		i++;
	}
	return (tetri);
}
