/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr_dup_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:52:38 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/04 21:31:35 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		str_len(t_lstr *lstr)
{
	int		len;

	len = 0;
	while (lstr)
	{
		if (lstr->str)
			len += ft_strlen(lstr->str);
		lstr = lstr->next;
	}
	return (len);
}

char			*lstr_dup_free(t_lstr **lstr)
{
	char	*str;
	t_lstr	*next;
	int		len;

	len = str_len(*lstr);
	if (len == 0)
		return ("");
	str = ft_strnew(str_len(*lstr));
	*str = '\0';
	while (*lstr)
	{
		if ((*lstr)->str)
			str = ft_strcat(str, (*lstr)->str);
		next = (*lstr)->next;
		free_lstr_one(&(*lstr));
		(*lstr) = next;
	}
	return (str);
}
