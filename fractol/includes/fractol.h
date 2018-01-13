/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:56:28 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/13 01:31:27 by yvillepo         ###   ########.fr       */
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
# define CENTER_X MAX_WIDTH / 2
# define CENTER_Y MAX_HEIGHT / 2
# define ITERATION_MAX 50
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
}					t_mlx;

unsigned int		*new_image(t_mlx *mlx, void **image);
void				fill_pixel(t_mlx *mlx, int x, int y,
		unsigned int color);
t_mlx				*init(int ac, char **av);
void				affiche(t_mlx *mlx);
void				mandelbrot_image(t_mlx *mlx, t_complex *c1, t_complex *c2);
int					key_hook(int keycode, void **p);

#endif
