/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 03:55:33 by hmartzol          #+#    #+#             */
/*   Updated: 2016/02/10 07:00:46 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	sf_try(t_piece piece, t_point pos, short tab[16])
{
	int out;

	out = !((piece.c[0] << (8 - pos.x)) & tab[pos.y]);
	out &= !((piece.c[1] << (8 - pos.x)) & tab[pos.y + 1]);
	out &= !((piece.c[2] << (8 - pos.x)) & tab[pos.y + 2]);
	out &= !((piece.c[3] << (8 - pos.x)) & tab[pos.y + 3]);
	return (out);
}

static void	sf_switch(t_piece piece, t_point pos, short tab[16])
{
	tab[pos.y] ^= (piece.c[0] << (8 - pos.x));
	tab[pos.y + 1] ^= (piece.c[1] << (8 - pos.x));
	tab[pos.y + 2] ^= (piece.c[2] << (8 - pos.x));
	tab[pos.y + 3] ^= (piece.c[3] << (8 - pos.x));
}

static int	sf_width(t_piece piece)
{
	int i;

	i = 4;
	while (piece.i & (16843009 << i))
		--i;
	return (3 - i);
}

static int	rec_solve(t_piece pieces[26], t_point truc, short tab[16],
		t_point *coord)
{
	while (coord->x < truc.x - sf_width(pieces[truc.y]))
	{
		while (coord->y < truc.x - sf_width(pieces[truc.y]) &&
				!sf_try(pieces[truc.y], coord[0], tab))
			coord->x = coord->x - sf_width(pieces[truc.y]) < size ?
				coord->x + 1 : 0 * (++coord->y);
		if (coord->y < truc.x - sf_width(pieces[truc.y]))
		{
			++truc.y;
			sf_switch(pieces[truc.y], coord[truc.y] = coord[0], tab);
			if (rec_solve(pieces, truc, tab, coord))
				return (1);
			else
			{
				sf_switch(pieces[truc.y], coord[0] = coord[truc.y], tab);
				--truc.y;
			}
		}
	}
	return (0);
}

t_point	*solve(t_piece pieces[26], int pcount)
{
	int		size;
	short	tab[16];
	t_point	*coord;
	int		current;

	if ((coord = (t_point*)ft_memalloc(sizeof(t_point) * 27)) == NULL)
		error();
	size = 2;
	while (size * size < pcount * 4)
		++size;
	ft_bzero(tab, 32);
	current = 0;
	while (current < pcount)
	{
		if (sf_try(pieces[current], coord[0], tab))
			sf_put(pieces[current++], coord[current] = coord[0], tab);
		coord->x = coord->x - 3 < size ? coord->x + 1 : 0 * (++coord->y);
	}
}
