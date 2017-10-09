/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 07:31:57 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 07:59:11 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = (((str[i] - 65) + 42) % 26) + 65;
		else if (str[i] >= 97 && str[i] <= 122)
			str[i] = (((str[i] - 97) + 42) % 26) + 97;
		i++;
	}
	return (str);
}
