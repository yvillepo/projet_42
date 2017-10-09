/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 15:50:05 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/18 15:54:25 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;

	i = 0;
	while (i < length)
	{
		tab[i] = f(tab[i]);
		i++;
	}
	return (tab);
}
