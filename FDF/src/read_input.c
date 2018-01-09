/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:21:43 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 11:12:19 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		fill_ligne(char *ligne, t_point3d **p3d, int y, int max_x)
{
	char	**tabnbr;
	char	**ptab;
	int		x;

	tabnbr = ft_strsplit(ligne, ' ');
	ptab = tabnbr;
	x = 0;
	while (*tabnbr)
	{
		if (!ft_isdigit(**tabnbr))
			exit_error("format map");
		fill_point(*p3d, x, y, (t_point)ft_atoi(*tabnbr));
		tabnbr++;
		x++;
		(*p3d)++;
	}
	if (x != max_x + 1)
		exit_error("format map");
	free_tabstr(&ptab);
}

static void		fill_struct(char **ligne, t_mlx *mlx)
{
	t_point			y;
	t_point3d		*p;

	y = 0;
	if (!(mlx->height * mlx->width))
		exit_error("format");
	mlx->p = ft_memalloc(sizeof(*(mlx->p)) * mlx->height * mlx->width);
	p = mlx->p;
	while (*ligne)
	{
		fill_ligne(*ligne, &p, y, mlx->max.x);
		ligne++;
		y++;
	}
}

void			read_input(char *argv, t_mlx *mlx)
{
	char	*str;
	char	**ligne;
	char	**tabnbr;

	str = read_file(argv);
	ligne = ft_strsplit(str, '\n');
	tabnbr = ft_strsplit(*ligne, ' ');
	mlx->height = len_tabstr(ligne);
	mlx->width = len_tabstr(tabnbr);
	mlx->max.x = mlx->width - 1;
	mlx->max.y = mlx->height - 1;
	free_tabstr(&tabnbr);
	mlx->nbpoint = mlx->width * mlx->height;
	fill_struct(ligne, mlx);
	mlx->max.z = max_min_z(mlx);
	def_scale(mlx);
	free_tabstr(&ligne);
	free(str);
	scale(mlx);
	centrer_points(mlx);
	color_point(mlx);
}
