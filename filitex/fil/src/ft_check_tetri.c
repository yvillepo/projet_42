/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:37:12 by mjuffard          #+#    #+#             */
/*   Updated: 2016/02/09 23:23:21 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	ft_check_tetri2(char *tab)
{
	int co;
	int i;

	i = -1;
	co = 0;
	if (ft_check_tetri1(tab))
		while (tab[++i])
			if (tab[i] == '#')
			{
				if (i + 1 < 20 && tab[i + 1] == '#')
					co++;
				if (i + 5 < 20 && tab[i + 5] == '#')
					co++;
				if (i - 1 >= 0 && tab[i - 1] == '#')
					co++;
				if (i - 5 >= 0 && tab[i - 5] == '#')
					co++;
			}
	return (co >= 6 ? 1 : 0);
}

int			ft_check_tetri1(char *tab)
{
	int		nb_diese;
	int		nb_point;
	int		nb_backslash_n;
	int		out;

	nb_diese = ft_strcntc(tab, '#');
	nb_point = ft_strcntc(tab, '.');
	nb_backslash_n = ft_strcntc(tab, '\n');
	if (nb_diese == 4 && nb_point == 12 && nb_backslash_n == 5)
	{
		out = ft_check_tetri2(tab) == 1 && tab[4] == '\n';
		out &= tab[9] == '\n' && tab[14] == '\n' && tab[19] == '\n';
		return (out);
	}
	if (nb_diese == 4 && nb_point == 12 && nb_backslash_n == 4)
		return (2);
	return (0);
}
