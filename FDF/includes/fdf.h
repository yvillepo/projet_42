/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:56:28 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/16 01:28:25 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx.h"
# include <math.h>
# define SCALE 25 
# define ECHAP 53
# define LEFT 126
# define UP 125
# define DOWN 124
# define RIGHT 123
# define PLUS 69
# define MOIN 78
# define W 2500
# define L 1300
# define PI 3,1415926535

typedef struct		s_point3D
{
	int					x;
	int					y;
	int					z;
}					t_point3D;

typedef struct		s_image
{
	void			*pim;
	unsigned int	*im;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_image			image;
	t_point3D		*p3D;
	t_point3D		*p;
	t_point3D		max;
	int				width;
	int				height;
	int				nbpoint;
	double			angle;
	int				scale;
}					t_mlx;

void				read_input(char *argv, t_mlx *mlx);
void				free_tabstr(char **str);
void				fill_point(t_point3D *p, int x, int y, int z);
void				affiche(t_mlx *mlx);
int					len_tabstr(char	**tabstr);
int					key_hook(int keycode, void	*p);
int					mouse_hook(int b, int x, int y, void *p);
int 				loop_hook(void *param);
int					expose_hook(void *param);
unsigned int		*new_image(void *mlx, void **image);
void				fill_pixel(unsigned int *image,int x, int y, unsigned int color);
void				rotate(t_mlx *m, char axe, double a);
void				rotate_key(t_mlx *m, int key, double a);
void				centrer_points(t_mlx *mlx);
void				trace_one_line(unsigned int *image, t_point3D *p1, t_point3D *p2);
void				trace_line(unsigned int *image, t_mlx *mlx, t_point3D *p);
void				zoom(t_mlx *mlx);
void				dezoom(t_mlx *mlx);
void				init(t_mlx **m, int ac, char **av);

#endif
