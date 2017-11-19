/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:01:18 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/13 07:44:02 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = ft_len(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_strnew(ft_len(n));
	if (s == NULL)
		return (0);
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (i >= 0 && s[i] != '-')
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
