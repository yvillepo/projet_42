/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:40:12 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/22 18:27:14 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*read_at_least_jump_line(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		ret;
	int		i;

	while ((ret = read(fd, buf, BUFf_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		if (ret = ft_strchr(str, '\n'))
		{
			str[str - ret] = '0';	
			return (str);
		}
		i = 1;
	}
	if (i = 0)
		return (NULL);
	return (str);
}
