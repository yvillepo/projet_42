#include "rtv1.h"
#include <fcntl.h>

t_vect	*read_vect(int fd)
{
	char 	*line;
	char 	**point;
	t_vect	*v;

	v = ft_malloc(sizeof(*v));
	if (get_next_line(fd, &line) == 0)
		exit_error("fichier emtree");
	point = ft_strsplit(line,' ');
	if(len_tabstr(point) < 3)
		exit_error("fichier entree");
	v->x = ft_atof(*point);
	v->y = ft_atof(point[1]);
	v->z = ft_atof(point[2]);
	free_tabstr(&point);
	free(line);
	return (v);
}

void		read_color(t_color *color, int fd)
{
	char 	*line;

	if (get_next_line(fd, &line) == 0)
		exit_error("fichier emtree");
	color->color = (unsigned int)ft_atoi_base(line, 16);
	free(line);
}

static void	read_camera(t_mlx *mlx, int fd)
{
	mlx->camera_pos = read_vect(fd);
	mlx->camera_dir = read_vect(fd);
}


static void		read_object(t_mlx *mlx, char *obj, int fd)
{
	t_object	*object;

	if (*obj == '\n')
		return;
	object = malloc(sizeof(*object));
	if (*obj == 's')
		read_object_sphere(object, fd);
	if (*obj == 'p')
		read_object_plane(object, fd);
	read_color(&(object->color), fd);
	if (mlx->object == 0)
		mlx->object = ft_lstnew(object, sizeof(*object));
	else
		ft_lstadd(&(mlx->object), ft_lstnew(object, sizeof(*object)));
}

void			print_camera(t_mlx *mlx)
{
	printf("pos camera %f %f %f\n",mlx->camera_pos->x,
			mlx->camera_pos->y, mlx->camera_pos->z);
	printf("dir camera %f %f %f\n",mlx->camera_dir->x,
			mlx->camera_dir->y, mlx->camera_dir->z);
}

static void		print_object(t_mlx *mlx)
{
	t_object	*object;
	t_list		*obj;
	int			i = 0;

	obj = mlx->object; 
	print_camera(mlx);
	while (obj)
	{
		object = obj->content; 
		if (object->type == SPHERE)
			print_sphere(object->form);
		if (object->type == PLANE)
			print_plane(object->form);
		printf("color : %x\n\n", object->color.color);
		obj = obj->next;
		i++;
	}
	printf("nb obj = %d\n",i);
}

void	parse(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	read_camera(mlx, fd);
	while (get_next_line(fd, &line))
	{
		read_object(mlx, line, fd);
		if (line)
			free(line);
		line = 0;
	}
	print_object(mlx);
}
