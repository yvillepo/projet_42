/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 22:34:46 by hmartzol          #+#    #+#             */
/*   Updated: 2016/02/09 23:16:28 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int	main(int argc, char **argv)
{
	char	*buff;
	int		fd;
	int		ret;
	int		x;

	if (!(buff = (char *)malloc(sizeof(char) * 22)))
		return (0);
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = 0;
		if ((x = ft_check_tetri1(buff)) != 1)
			break ;
	}
	close(fd);
	if (x == 2 && ret == 0)
		ft_putendl("OK");
	return (0);
}
