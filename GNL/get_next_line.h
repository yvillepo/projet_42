/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:16:52 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/28 05:56:19 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_fd
{
	int			fd;
	char		*str;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
