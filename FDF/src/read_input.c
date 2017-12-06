/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:21:43 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/06 20:26:20 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>

static void	fill_struct(char **ligne, t_mlx *mlx)
{
	char		**tabnbr;
	int			x;
	int			y;
	t_point3D		*p3D;

	y = 0;
	p3D = mlx->p3D;
	while (*ligne)
	{
		tabnbr = ft_strsplit(*ligne, ' ');
		x = 0;
		while (*tabnbr)
		{
			if (!ft_isdigit(**tabnbr))
				exit_error("format");
			fill_point(p3D, x, y, ft_atoi(*tabnbr));
			tabnbr++;
			x++;
			p3D++;
		}
		ligne++;
		y++;
	}
	printf ("x = %d, y = %d \n",x,y);
}
/*
 ** pensser aux fuite memoirs
*/
void		read_input(char	*argv, t_mlx *mlx)
{
	char	*str;
	char	**ligne;
	char	**tabnbr;

	str = read_file(argv);
	ligne = ft_strsplit(str, '\n');
	tabnbr = ft_strsplit(*ligne, ' ');
	free_tabstr(tabnbr);
	free(tabnbr);
	mlx->nbpoint = len_tabstr(ligne) * len_tabstr(tabnbr);
	mlx->p3D = ft_memalloc(sizeof(*(mlx->p3D)) * mlx->nbpoint);
	fill_struct(ligne, mlx);
}
