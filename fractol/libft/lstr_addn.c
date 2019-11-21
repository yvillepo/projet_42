/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr_addn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:53:29 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/04 17:40:26 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lstr		*lstr_new(char *str)
{
	t_lstr	*lstr;

	if (!(lstr = malloc(sizeof(*lstr))))
		return (NULL);
	lstr->str = str;
	lstr->next = NULL;
	return (lstr);
}

t_lstr		*lstr_addn(t_lstr *lstr, char *str)
{
	if (!lstr)
	{
		lstr = lstr_new(str);
		return (lstr);
	}
	lstr->next = lstr_new(str);
	return (lstr->next);
}
