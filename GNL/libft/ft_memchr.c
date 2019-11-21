/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:26:19 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/12 17:45:03 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*s_ptr;

	ch = (unsigned char)c;
	s_ptr = (unsigned char*)s;
	while (n)
	{
		if (*s_ptr == ch)
			return ((void*)s_ptr);
		s_ptr++;
		n--;
	}
	return (NULL);
}
