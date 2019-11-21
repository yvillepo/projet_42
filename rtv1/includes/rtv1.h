/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.44.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 01:56:28 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 08:21:26 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

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
# define PLANE 1
# define CYL 2
# define CONE 3
# define T_Z 6
# define PI 3.1415926535897932384

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
	t_vect			*pos;
}					t_plane;

typedef struct		s_cyl
{
	t_vect			*dir;
	t_vect			*pos;
	double			r;
}					t_cyl;

typedef struct		s_cone
{
	t_vect			*dir;
	t_vect			*pos;
	double			a;
}					t_cone;

typedef struct		s_mlx
{
	int				width;
	int				height;
	double			h;
	void			*mlx;
	void			*win;
	t_vect			*camera_pos;
	t_vect			*camera_dir;
	t_vect			*light;
	double			fov;
	t_point			res;
	double			pitch;
	int				ombre;
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
void				parse(t_mlx *mlx, char *file);
void				free_tabstr(char ***tab);
int					len_tabstr(char **tabstr);
void				trace_ray(t_mlx *mlx, t_list *object);
void				print_vect(char *s, t_vect *v);
t_vect				unit_scale(double k, t_vect *v);
t_vect				*calc_point(t_line *line, double t);
double				calc_height_screen(t_mlx *mlx);
void				read_sphere(t_sphere *sphere, int fd);
double				inter_sphere(t_sphere *sphere, t_line *line);
t_vect				*read_vect(int fd);
t_color				intersec(t_mlx *mlx, int i, int j, t_list *object);
t_vect				*read_vect(int fd);
void				read_object_sphere(t_object *object, int fd);
void				read_plane(t_plane *plane, int fd);
void				read_object_plane(t_object *object, int fd);
void				print_sphere(t_sphere *sphere);
void				print_plane(t_plane *plane);
double				inter_plane(t_plane *plane, t_line *line);
void				v_print(t_vect *v);
int					v_is_unit(t_vect *v);
void				v_unit(t_vect *v);
double				v_l(t_vect *v);
t_vect				*p_normal(t_vect *u, t_vect *v);
t_vect				*find_octo(t_vect *v);
double				solv_2nd(double a, double b, double c);
void				read_object_cyl(t_object *object, int fd);
void				print_cyl(t_cyl *cyl);
double				inter_cyl(t_cyl *cyl, t_line *l);
double				inter_cone(t_cone *cone, t_line *l);
void				print_cone(t_cone *cone);
void				read_object_cone(t_object *object, int fd);
t_vect				*v_add(t_vect *u1, t_vect *u2);
t_vect				*v_sub(t_vect *u1, t_vect *u2);
double				v_mult(t_vect *u1, t_vect *u2);
double				deg_to_rad(double a);
t_vect				*v_cross(t_vect *u1, t_vect *u2);
void				read_camera(t_mlx *mlx, int fd);
double				intersec_unit(t_object *obj, t_line *line);
double				is_shadow(t_mlx *mlx, t_line *cam, double d);
void				read_light(t_mlx *mlx, int fd);
void				rotate_xyz(t_vect *p, double a, int axe);
void				rot_obj_x(t_object *obj, double angle, int axe);
void				read_rot(t_mlx *mlx, char *line, int i);
double				v_scale(t_vect *u, t_vect *v);
t_color				mult_color(t_color color, double mult);
double				calc_light(t_mlx *mlx, t_line *cam,
		t_object *obj, double t);
void				clear_im(t_mlx *mlx, unsigned int *im);
void				read_translation(t_mlx *mlx, char *line, int fd, int i);
void				read_color(t_color *color, int fd);
void				jump_coment(char **line);
void				jump_coment2(char **line);
void				calc_ray(t_mlx *mlx, t_vect *dir, double x, double y);
int					is_nul(t_vect *v);

#endif
