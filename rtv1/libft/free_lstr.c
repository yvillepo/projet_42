/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:21:58 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/04 17:39:48 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lstr	*free_lstr_one(t_lstr **lstr)
{
	t_lstr *next;

	if (!*lstr)
		return (NULL);
	next = (*lstr)->next;
	if ((*lstr)->str)
		free((*lstr)->str);
	free(*lstr);
	*lstr = NULL;
	return (next);
}

void	free_lstr(t_lstr **lstr)
{
	if (!*lstr)
		return ;
	free_lstr(&((*lstr)->next));
	free_lstr_one(lstr);
}
