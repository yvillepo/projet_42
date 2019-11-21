/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:27:10 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/12 17:45:07 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1_ptr;
	const unsigned char *s2_ptr;
	size_t				i;

	if (n == 0)
		return (0);
	s1_ptr = s1;
	s2_ptr = s2;
	i = 0;
	while (s1_ptr[i] == s2_ptr[i] && (i + 1) < n)
		i++;
	return (s1_ptr[i] - s2_ptr[i]);
}
