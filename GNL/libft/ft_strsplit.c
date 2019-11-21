/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:47:00 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/14 15:29:58 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_split(const char **src, char c)
{
	char	*src1;
	int		i;
	char	*a;

	i = 0;
	while (**src == c)
		(*src)++;
	while ((*src)[i])
		i++;
	src1 = (char*)malloc(i + 1);
	a = src1;
	if (src1 != NULL)
	{
		while (**src != c && **src)
		{
			*src1 = **src;
			(*src)++;
			src1++;
		}
		*src1 = '\0';
	}
	return (a);
}

static int	nb_mots(const char *s, char c)
{
	int cmp;

	cmp = 0;
	while (*s)
	{
		if (*s != c)
		{
			cmp++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (cmp);
}

char		**ft_strsplit(const char *str, char c)
{
	char	**tab;
	int		nb_m;
	int		i;

	if (!str)
		return (NULL);
	while (*str == c)
		str++;
	nb_m = nb_mots(str, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * nb_m + 1)))
		return (NULL);
	i = 0;
	while (i < nb_m)
	{
		tab[i] = ft_strdup_split(&str, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
