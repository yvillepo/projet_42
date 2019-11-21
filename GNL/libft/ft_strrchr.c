/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:47:00 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/12 17:47:02 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	ch;
	int		length;

	length = ft_strlen(s);
	ptr = (char*)s + length;
	ch = c;
	while (ptr >= s)
	{
		if (*ptr == ch)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
