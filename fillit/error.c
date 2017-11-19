/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 08:15:27 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/17 11:09:48 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_puterror("error");
	ft_puterror("\n");
}

void	close_file(int fd)
{
	if (close(fd) == -1)
		error();
}

void	close_error(int fd)
{
	error();
	close_file(fd);
	exit(0);
}
