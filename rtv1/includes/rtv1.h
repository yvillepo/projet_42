/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.44.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:56:28 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/05 10:55:21 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#include "stdio.h"

# include "mlx.h"
# include "libft.h"
# include <math.h>
# define ECHAP 53
# define LEFT 123
# define UP 126
# define DOWN 125
# define RIGHT 124
# define PLUS 69
# define MOIN 78
# define UN 83
# define DEUX 84
# define T_A 0
# define T_W 13
# define T_S 1
# define T_D 2
# define T_R 15
# define T_N 45
# define T_X 7
# define SPACE 49
# define ENTER 36
# define ROUGE 2
# define VERT 1
# define BLEU 0
# define MANDELBROT 2
# define JULIA 0
# define BURNING 1
# define MAX_ITERATION 50
# define TRANSLATION 0.20
# define PERCENT_ZOOM 150
# define DEFAULT_HEIGHT 800
# define SPHERE 0
# define T_Z 6

typedef union		u_color
{
	unsigned char	rgb[4];
	unsigned int	color;
}					t_color;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_line
{
	t_vect			*dir;
	t_vect			*origin;
}					t_line;

typedef struct		s_image
{
	void			*pim;
	unsigned int	*im;
}					t_image;

typedef struct		s_object
{
	int				type;
	void			*form;
	t_color			color;
}					t_object;

typedef	struct		s_sphere
{
	t_vect			*centre;
	double			rayon;
}					t_sphere;

typedef struct		s_plane
{
	t_vect			*normal;
	double			d;
}					t_plane;

typedef struct		s_mlx
{
	int				width;
	int				height;
	void			*mlx;
	void			*win;
	t_vect			*camera_pos;
	t_vect			*camera_dir;
	t_point			res;
	t_point			*pitch;
	t_list			*object;
	t_image			image;
}					t_mlx;

unsigned int		*new_image(t_mlx *mlx, void **image);
void				fill_pixel(t_mlx *mlx, int x, int y, unsigned int color);
t_mlx				*init(int ac, char **av);
void				affiche(t_mlx *mlx);
t_vect				*new_vect(double x, double y, double z);
t_point				*new_point(double x, double y);
int					key_hook(int keycode, void *p);
int					mouse_hook(int button, int x, int y, void *param);
double				inter_sphere(t_mlx *mlx, t_vect *dir, t_sphere *sphere, t_vect *res);
void				parse(t_mlx *mlx, char *file);
void				free_tabstr(char ***tab);
int					len_tabstr(char **tabstr);
void				trace_ray(t_mlx *mlx, t_list *object);
int		is_between(t_vect *A, t_vect *B, t_vect *M);
double				is_coplanar(t_vect *A, t_vect *B);
void				print_vect(char *s, t_vect *v);
t_vect				unit_scale(double k, t_vect *v);
void				calc_point(t_line *line, double t, t_vect *res);

#endif
