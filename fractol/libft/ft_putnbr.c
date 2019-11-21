/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 21:29:02 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/14 15:58:06 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	affiche_nombre(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i] != '\0')
		i++;
	while (i > 0)
	{
		i--;
		ft_putchar(nbr[i]);
	}
}

void		ft_putnbr(int nb)
{
	char		nombre[20];
	int			i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
	}
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (nb != 0)
	{
		if (nb < 0)
			nombre[i] = '0' - (nb % 10);
		else
			nombre[i] = '0' + (nb % 10);
		nb = nb / 10;
		i++;
	}
	nombre[i] = '\0';
	affiche_nombre(nombre);
}
