#ifndef WOLF_H
#define WOLF_H

# include "mlx.h"
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

# define WIDTH 800
# define HEIGHT 800
# define SIZE_BLOCK 10
# define NB_TEXTURE 1

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

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_image			image;
	int				**map;
	int				texture;
}					t_mlx;

t_mlx				*init(void);
void			 	edit_block(t_mlx *mlx, int x, int y);
void				draw_block(t_mlx *mlx, int x, int y, int texture);
void				fill_pixel(t_mlx *mlx, int x1,
		int y1, unsigned int color);
void				affiche(t_mlx *mlx);
int					mouse_hook(int button, int x, int y, void *param);
unsigned int		*new_image(t_mlx *mlx, void **image);
int					key_hook(int keycode, void *p);

#endif 
