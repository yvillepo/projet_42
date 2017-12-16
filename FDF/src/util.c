/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:07:56 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/14 20:14:32 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tabstr(char **tabstr)
{
	if (!tabstr)
		return ;
	while (*tabstr)
	{
		free(*tabstr);
		tabstr++;
	}
	*tabstr = NULL;
}

int		len_tabstr(char	**tabstr)
{
	int		i;

	i = 0;
	while (*tabstr)
	{
		tabstr++;
		i++;
	}
	return (i);
}
