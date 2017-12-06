/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:56:28 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/06 21:19:02 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx.h"
# define TAILLE_CARREAUX 10
# define ECHAP 53

typedef struct		s_point3D
{
	int				x;
	int				y;
	int				z;
}					t_point3D;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_point3D		*p3D;
	t_point3D		eyes;
	int				nbpoint;
}					t_mlx;

void				read_input(char *argv, t_mlx *mlx);
void				free_tabstr(char **str);
void				fill_point(t_point3D *p, int x, int y, int z);
void				affiche(t_mlx *mlx);
int					len_tabstr(char	**tabstr);

int		key_hook(int keycode, void	*p);
int		mouse_hook(int b, int x, int y, void *p);
int 	loop_hook(void *param);
int		expose_hook(void *param);

#endif
