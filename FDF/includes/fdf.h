/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:56:28 by yvillepo          #+#    #+#             */
/*   Updated: 2017/12/19 11:09:28 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# define SCALE 25
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
# define MAX_HEIGHT 1320
# define MAX_WIDTH 2550
# define SECURE 1.20
# define SCALE_MAX 22
# define PI 3.1415926535897932384

typedef double		t_point;

typedef union		u_color
{
	char			rgb[4];
	unsigned int	color;
}					t_color;

typedef struct		s_point3d
{
	t_point				x;
	t_point				y;
	t_point				z;
	t_color				c;
}					t_point3d;

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
	t_point3d		*p;
	t_point3d		centre;
	t_point3d		max;
	t_point			z_min;
	int				width;
	int				height;
	int				nbpoint;
	int				width_window;
	int				height_window;
	double			angle;
	double			scale;
}					t_mlx;

void				read_input(char *argv, t_mlx *mlx);
void				free_tabstr(char ***str);
void				fill_point(t_point3d *p, int x, int y, int z);
void				affiche(t_mlx *mlx);
int					len_tabstr(char	**tabstr);
int					key_hook(int keycode, void	**p);
int					expose_hook(void *param);
unsigned int		*new_image(t_mlx *mlx, void **image);
void				fill_pixel(t_mlx *mlx, int x, int y,
		unsigned int color);
void				rotate_key(t_mlx *m, int key, double a);
void				centrer_points(t_mlx *mlx);
void				trace_line(t_mlx *mlx, t_point3d *p);
void				zoom(t_mlx *mlx, double coef);
void				init(t_mlx **m, int ac, char **av);
void				rotate_z(t_mlx *m, double a);
void				rotate_y(t_mlx *m, double a);
void				rotate_x(t_mlx *m, double a);
double				deg_to_rad(double a);
void				scale(t_mlx *mlx);
void				centrer_points(t_mlx *mlx);
void				color_point(t_mlx *mlx);
void				translation(t_mlx *mlx, int key, int offset);
void				free_mlx(t_mlx **m);
int					max_min_z(t_mlx *mlx);
void				def_scale(t_mlx *mlx);

#endif
