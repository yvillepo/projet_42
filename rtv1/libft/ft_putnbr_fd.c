/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:45:13 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/14 16:50:19 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	affiche_nombre(char *nbr, int fd)
{
	int i;

	i = 0;
	while (nbr[i] != '\0')
		i++;
	while (i > 0)
	{
		i--;
		ft_putchar_fd(nbr[i], fd);
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	char		nombre[20];
	int			i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
	}
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
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
	affiche_nombre(nombre, fd);
}
