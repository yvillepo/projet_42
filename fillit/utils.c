/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:34:57 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/19 16:01:45 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*new_tetri(void)
{
	t_tetri *tetri;

	if(!(tetri = (t_tetri*)malloc(sizeof(*tetri))))
		return (NULL);
	tetri->letter = 0;
	tetri->next = NULL;
	return (tetri);
}

void	tetri_list_add(t_tetri **begin_list, t_tetri *tetri)
{
	t_tetri	*tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tetri;
	}
}
