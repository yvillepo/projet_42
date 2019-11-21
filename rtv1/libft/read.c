/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:28:51 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/17 12:26:23 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

char	*read_fd(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	t_lstr	*lstr;
	t_lstr	*current;
	int		i;

	lstr = lstr_new(0);
	current = lstr;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		current = lstr_addn(current, ft_strdup(buf));
		i = 1;
	}
	if (ret < 0)
		exit_error("read file");
	if (!i)
		exit_error("file vide");
	return (lstr_dup_free(&lstr));
}

char	*read_file(char *str)
{
	int		fd;
	char	*s;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit_error("open file");
	s = read_fd(fd);
	return (s);
}
