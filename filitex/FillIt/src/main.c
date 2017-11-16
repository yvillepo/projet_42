/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/02/10 04:38:20 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

const unsigned long int g_ref[19] = {49344, 240, 2155905152, 49248, 4243584,
	24768, 8437824, 16608, 8437888, 57408, 4243520, 32992, 4210880, 57376,
	12615808, 8416, 8421568, 57472, 12599360};

static int	load_pieces(char *file, t_piece pieces[26])
{
	int	i;
	int	pcount;
	int j;

	i = -1;
	pcount = -1;
	while (file[++i] && file[i - (i > 0)] && (j = -1) && pcount < 26)
	{
		pieces[++pcount].i = 0;
		while (++j < 20 && file[i + j])
			if (j % 5 != 4)
			{
				if (file[i + j] != '.' && file[i + j] != '#')
					error();
				pieces[pcount].c[j / 5] |=
					(file[i + j] == '#') << (7 - (j % 5));
			}
			else if (file[i + j] != '\n')
				error();
		if (file[(i += j)] != '\n' && file[i])
			error();
	}
	return (pcount + 1);
}

static void	prepare_piece(t_piece pieces[26], int pcount)
{
	int	i;
	int	j;
	int	ok;

	i = -1;
	while (++i < pcount)
	{
		if (!pieces[i].i)
			error();
		while (!pieces[i].c[0])
			pieces[i].i >>= 8;
		while (!((pieces[i].c[0] & 128) | (pieces[i].c[1] & 128) |
				(pieces[i].c[2] & 128)))
			pieces[i].i <<= 1;
		j = -1;
		ok = 0;
		while (++j < 19 && !ok)
			ok |= (g_ref[j] == pieces[i].i);
		if (!ok)
			error();
	}
}

int			main(int argc, char **argv)
{
	t_piece pieces[26];
	char	*file;
	int		pcount;
	int		fd;

	if (argc != 2)
		error();
	fd = open(argv[1], O_RDONLY);
	file = ft_readfile(fd);
	close(fd);
	pcount = load_pieces(file, pieces);
	prepare_piece(pieces, pcount);
	solve(pieces, pcount);
	return (0);
}
