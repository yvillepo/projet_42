#include "wolf.h"
#include <fcntl.h>

t_vect	*read_vect(int fd)
{
	char 	*line;
	char 	**point;
	t_vect	*v;

	v = ft_malloc(sizeof(*v));
	if (get_next_line(fd, &line) == 0)
		exit_error("erreur fichier emtree");
	point = ft_strsplit(line,' ');
	if(len_tabstr(point) < 3)
		exit_error("erreur fichier entree");
	v->x = ft_atoi(*point);
	v->y = ft_atoi(point[1]);
	v->z = ft_atoi(point[2]);
	free_tabstr(&point);
	free(line);
	return (v);
}

void		read_color(t_color *color, int fd)
{
	char 	*line;

	if (get_next_line(fd, &line) == 0)
		exit_error("erreur fichier emtree");
	printf("%x", ft_atoi_base(line, 16));
	color->color = ft_atoi_base(line, 16);
	free(line);
}

static void	read_camera(t_mlx *mlx, int fd)
{
	mlx->camera_pos = read_vect(fd);
	mlx->camera_dir = read_vect(fd);
}

static void		read_sphere(t_sphere *sphere, int fd)
{
	char *line;

	sphere->centre = read_vect(fd);
	if (get_next_line(fd, &line) == 0)
		exit_error("erreur fichier emtree");
	sphere->rayon = ft_atoi(line);
	free (line);
}

static void		read_object(t_mlx *mlx, char *obj, int fd)
{
	t_object	*object;

	object = malloc(sizeof(*object));
	if (mlx->object == 0)
		mlx->object = ft_lstnew(object, 1);
	else
	{
		ft_lstadd(&(mlx->object), ft_lstnew(object, 1));
	}
	if (*obj == 's')
	{
	//	object->type = SPHERE;
		((t_object*)(mlx->object->content))->type = SPHERE;
		((t_object*)(mlx->object->content))->form = ft_malloc(sizeof(t_sphere));
	//	object->form = ft_malloc(sizeof(t_sphere));
	//	read_sphere(object->form, fd);
		read_sphere(((t_object*)(mlx->object->content))->form, fd);
	}
	read_color(&(((t_object*)(mlx->object->content))->color), fd);
	
}

void	parse(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;
	char	**data;

	fd = open(file, O_RDONLY);
	read_camera(mlx, fd);
	while (get_next_line(fd, &line))
	{
		read_object(mlx, line, fd);
		free(line);
	}
}
