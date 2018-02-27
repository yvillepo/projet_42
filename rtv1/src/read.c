#include "wolf.h"
#include <fcntl.h>

void	read_vect(t_vect *vect, char **point)
{
	vect->x = ft_atoi(*point);
	vect->y = ft_atoi(point[1]);
	vect->z = ft_atoi(point[2]);
}

static int		read_object(t_mlx *mlx, int fd)
{
	char	*line;
	char	**data;

	if (get_next_line(fd, &line) == 0)
		return (0);
	data = ft_strsplit(line,' ');
	//read_vect(mlx->
	return (1);
}

void	parse(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
}
