/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:01:41 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/12 20:11:11 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int cmp;

	cmp = 0;
	if (!n)
		return (2);
	if (n < 0)
		cmp++;
	while (n)
	{
		n = n / 10;
		cmp++;
	}
	return (cmp + 1);
}

static char	*itoa_negatif(int n)
{
	char	*str_nbr;
	char	*s;

	if (!(str_nbr = (char*)malloc(len(n))))
		return (NULL);
	s = str_nbr;
	while (n)
	{
		*str_nbr++ = '0' - (n % 10);
		n = n / 10;
	}
	*str_nbr++ = '-';
	*str_nbr = 0;
	return (s);
}

static char	*itoa_positif(int n)
{
	char	*str_nbr;
	char	*s;

	if (!(str_nbr = (char*)malloc(len(n))))
		return (NULL);
	s = str_nbr;
	if (n == 0)
	{
		*str_nbr = '0';
		str_nbr++;
	}
	while (n)
	{
		*str_nbr++ = '0' + (n % 10);
		n = n / 10;
	}
	*str_nbr = 0;
	return (s);
}

char		*ft_itoa(int n)
{
	char	*str_nbr;

	if (n < 0)
		str_nbr = itoa_negatif(n);
	else
		str_nbr = itoa_positif(n);
	if (str_nbr)
		return (ft_rev(str_nbr));
	return (NULL);
}
