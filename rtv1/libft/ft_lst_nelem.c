/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_nelem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:46:43 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/21 21:15:04 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_nelem(t_list *l, int nb)
{
	if (nb == 0)
		return (l);
	while (nb-- && l)
		l = l->next;
	if (l)
		return (l);
	exit_error("ft_lst_nelem : l element n existe pas");
	return (NULL);
}
