/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:52:47 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/13 17:01:41 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*trs;
	char	*t;

	if (!s)
		return (NULL);
	if (!(trs = (char*)malloc(len + 1)))
		return (NULL);
	t = trs;
	while (start--)
		s++;
	while (len--)
	{
		*t = *s;
		t++;
		s++;
	}
	*t = 0;
	return (trs);
}
