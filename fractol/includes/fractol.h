/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:56:28 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/25 05:07:26 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "mlx.h"
# include <math.h>
# include "libft.h"
# include "fenaitre.h"
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
# define SPACE 49 
# define ENTER 36
# define ROUGE 2
# define VERT 1
# define BLEU 0
# define MANDELBROT 0
# define JULIA 1
# define MAX_ITERATION 50
# define TRANSLATION 0.20 
# define PERCENT_ZOOM 150

typedef union		u_color
{
	unsigned char	rgb[4];
	unsigned int	color;
}					t_color;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_image
{
	void			*pim;
	unsigned int	*im;
}					t_image;

typedef struct		s_mandelbrot
{
	t_complex		*cmin;
	t_complex		*cmax;
	double			quantum;
	t_image			image;
}					t_mandelbrot;

typedef struct		s_julia
{
	t_complex		*zmin;
	t_complex		*zmax;
	t_complex		*c;
	double			quantum;
	t_image			image;
	int				mode_zoom;
}					t_julia;

typedef struct		s_mlx
{
	int				width;
	int				height;
	int				iteration;
	void			*mlx;
	void			*win;
	t_mandelbrot	*mandelbrot;
	t_julia			*julia;
	int				order_color[3];
	int				fractale;
	t_image			*image;
}					t_mlx;

unsigned int		*new_image(t_mlx *mlx, void **image);
void				fill_pixel(t_mlx *mlx, int x, int y,
		unsigned int color);
t_mlx				*init(int ac, char **av);
void				affiche(t_mlx *mlx);
void				mandelbrot_image(t_mlx *mlx);
void				init_quantum(t_mlx *mlx);
int					key_hook(int keycode, void *p);
void				zoom_fractale(t_mlx *mlx, t_point *zoom_point, int sens_zoom);
t_point				*new_point(int x, int y);
int					mouse_hook(int button, int x, int y, void *param);
void				affiche_mlx(t_mlx *mlx);
void				mandelbrot_image1(t_mlx *mlx,t_complex *c1,t_complex *c2);
void				mlx_free(t_mlx **m);
unsigned int					color(float percent);
unsigned int		color1(double percent);
void				translation_fractale(t_mlx *mlx, int key, double translation);
void				change_color(int tab[3]);
unsigned int		color2(double percent, int ordre_color[3]);
int					input_julia(int x, int y, t_mlx *mlx);
void				julia_image(t_mlx *mlx);
void				affiche_fractal(t_mlx *mlx);
t_complex			*cmin_fractole(t_mlx *mlx);
t_complex			*cmax_fractole(t_mlx *mlx);
void				switch_mode(t_julia *julia);
void				reset_fractole(t_mlx *mlx);

#endif
