/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:07:56 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 11:12:40 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	free_tab(char **tabstr)
{
	if (!tabstr)
		return ;
	while (*tabstr)
	{
		if (*tabstr)
			free(*tabstr);
		tabstr++;
	}
	*tabstr = NULL;
}

void	free_tabstr(char ***tabstr)
{
	free_tab(*tabstr);
	if (*tabstr)
		free(*tabstr);
}

int		len_tabstr(char **tabstr)
{
	int		i;

	i = 0;
	while (*tabstr)
	{
		tabstr++;
		i++;
	}
	return (i);
}

void	free_mlx(t_mlx **m)
{
	t_mlx	*mlx;

	mlx = *m;
	if (mlx->p)
		free(mlx->p);
	if (mlx->image.pim)
		mlx_destroy_image(mlx, mlx->image.pim);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
	free(mlx);
}
