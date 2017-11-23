/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:40:12 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/23 19:16:51 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd		*new_struct_fd(int fd)
{
	t_fd	*new;
	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	return (new);
}

static int		read_jump_line(t_fd *fd_str, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		ret;

	str = fd_str->str;
	while ((ret = read(fd_str->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		if (tmp)
			str = ft_strjoin(tmp, buf);
		else 
			str = buf;
		ft_strdel(&tmp);
		if ((tmp = ft_strchr(str, '\n')))
		{
			*tmp = '\0';
			fd_str->str = ++tmp;
			*line = str;
			return (1);
		}
	}
	*line = str;
	return (0);
}

static t_fd		*search_fd(int fd, t_list **head)
{
	t_fd	*fd_str;
	t_list	*l_fd;

	l_fd = *head;
	while (l_fd)
	{
		if ((((t_fd*)(l_fd->content))->fd = fd))
			return ((t_fd*)(l_fd->content));
		l_fd = l_fd->next;
	}
	fd_str = new_struct_fd(fd);
	ft_lstadd(head, ft_lstnew(fd_str, sizeof(fd_str)));
	return (fd_str);
}

static char	*sub_first_line(char	**str)
{
	char	*saut;
	int		len_line;
	char	*s;

	s = *str;
	if (!(saut = ft_strchr(s, '\n')))
		return (0);
	len_line = saut - s;
	s = ft_strdup(saut);
	ft_strdel(str);
	*str = s;
	return (ft_strsub(*str, 0, len_line + 1));
}

int get_next_line(const int fd, char **line)
{
	 static t_list	*l_fd = NULL;
	 t_fd			*fd_str;

	 fd_str = search_fd(fd, &l_fd);
	 if ((*line = sub_first_line(&(fd_str->str))))
		 return (1);
	return (read_jump_line(fd_str, line));
}
