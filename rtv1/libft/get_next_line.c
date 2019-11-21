/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:40:12 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/04 20:52:34 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_struct_fd(t_fd **fd_str, int fd)
{
	t_fd	*prec;
	t_fd	*current;

	prec = *fd_str;
	current = *fd_str;
	if (!fd_str || !*fd_str)
		return ;
	if ((*fd_str)->fd == fd)
	{
		*fd_str = (*fd_str)->next;
		if (current->str)
			ft_strdel(&(current->str));
		free(current);
		return ;
	}
	while (current->fd != fd)
	{
		prec = current;
		current = current->next;
	}
	prec->next = current->next;
	if (current->str)
		ft_strdel(&(current->str));
	free(current);
}

static int		read_file_gnl(t_fd *fd_str)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		ret;
	int		i;

	tmp = NULL;
	i = 0;
	while ((ret = read(fd_str->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (tmp)
			str = ft_strjoin(tmp, buf);
		else
			str = ft_strdup(buf);
		ft_strdel(&tmp);
		tmp = str;
		i = 1;
	}
	if (ret < 0)
		exit_error("read file");
	if (i)
		fd_str->str = str;
	return (0);
}

static void		search_fd(int fd, t_fd **head, t_fd **fd_str)
{
	*fd_str = *head;
	while (*fd_str)
	{
		if ((*fd_str)->fd == fd)
			return ;
		*fd_str = (*fd_str)->next;
	}
	if (!(*fd_str = malloc(sizeof(**fd_str))))
		return ;
	(*fd_str)->fd = fd;
	(*fd_str)->str = NULL;
	(*fd_str)->next = NULL;
	if (*head)
	{
		(*fd_str)->next = *head;
		*head = *fd_str;
	}
	else
		*head = *fd_str;
}

static int		sub_first_line(t_fd **fd_str, char **line)
{
	char	*saut;
	int		len_line;
	char	*s;

	s = (*fd_str)->str;
	if (!s || !*s)
		return (0);
	if ((saut = ft_strchr(s, '\n')) == NULL)
	{
		s = ft_strdup(s);
		*line = s;
		ft_strdel(&(*fd_str)->str);
		(*fd_str)->str = 0;
		return (1);
	}
	len_line = saut - s;
	*saut = '\0';
	if (*(saut + 1) == '\0')
		s = NULL;
	else
		s = ft_strdup(saut + 1);
	*line = ft_strsub((*fd_str)->str, 0, len_line);
	ft_strdel(&(*fd_str)->str);
	(*fd_str)->str = s;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd		*l_fd = NULL;
	int				ret;
	t_fd			*fd_str;

	search_fd(fd, &l_fd, &fd_str);
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (read_file_gnl(fd_str) == -1)
		return (-1);
	if ((ret = sub_first_line(&fd_str, line)) == 0)
	{
		free_struct_fd(&l_fd, fd);
	}
	return (ret);
}
