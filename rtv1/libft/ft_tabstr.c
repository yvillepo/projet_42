/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 03:56:24 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:44:44 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tabstr)
{
	if (!tabstr)
		return ;
	while (*tabstr)
	{
		if (*tabstr)
			free(*tabstr);
		tabstr++;
	}
	*tabstr = NULL;
}

int			len_tabstr(char **tabstr)
{
	int	i;

	i = 0;
	while (*tabstr)
	{
		tabstr++;
		i++;
	}
	return (i);
}

void		free_tabstr(char ***tabstr)
{
	free_tab(*tabstr);
	if (*tabstr)
		free(*tabstr);
}
