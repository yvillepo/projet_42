/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:08:32 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:44:14 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	calc_digit(const char *c)
{
	if (*c >= '0' && *c <= '9')
		return (*c - '0');
	if (*c >= 'a' && *c <= 'z')
		return (*c - 'a' + 10);
	if (*c >= 'A' && *c <= 'Z')
		return (*c - 'A' + 10);
	return (17);
}

static int			calcul(const char *str, int base)
{
	unsigned int	result;
	unsigned int	digit;

	result = 0;
	while (*str)
	{
		digit = calc_digit(str);
		str++;
		if (digit > 16)
			break ;
		result = (result * base) + digit;
	}
	return ((int)result);
}

int					ft_atoi_base(const char *str, int base)
{
	unsigned int	result;
	int				sign;

	result = 0;
	sign = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = *str == '-';
		str++;
	}
	result = calcul(str, base);
	if (sign)
		return (-result);
	return (result);
}
