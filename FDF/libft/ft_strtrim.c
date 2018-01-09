/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:57:46 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/14 17:20:50 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(const char *s)
{
	const char	*s1;

	s1 = s;
	if (!*s)
		return (0);
	while (*s1)
		s1++;
	s1--;
	while (*s1 == ' ' || *s1 == '\n' || *s1 == '\t')
		s1--;
	return (s1 - s + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*s1;
	int		size;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	size = ft_size(s);
	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	s1 = str;
	while (size--)
		*str++ = *s++;
	*str = 0;
	return (s1);
}
