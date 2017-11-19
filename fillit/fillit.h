/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:43 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/19 16:40:47 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_tetriminos
{
	t_point				two;
	t_point				three;
	t_point				four;
	char				letter;
	struct s_tetriminos	*next;
}						t_tetri;

typedef struct			s_map
{
	int					size;
	char				**map;
}						t_map;

int						read_input(const char *file, t_tetri *tetri_list);
t_tetri					*get_tetri_pos(char *block, t_tetri *tetri, int i);
int						block_valid(char *block);
void					error();
void					close_file(int fd);
void					close_error(int fd);
void					tetri_list_add(t_tetri **begin_list, t_tetri *tetri);
t_tetri					*new_tetri(void);
t_tetri					*new_tetri_list(void);
unsigned int			insert_tetri(t_map *map, t_tetri *tetri, int *x, int *y);
void					retire_tetri(t_map *m, t_tetri *tetri, int x, int y);
void					free_map(t_map *map);
void					print_map(t_map *map);
t_map					*map_new(int size);
t_map					*solve(t_tetri *ltetri, unsigned int nb_tetri);
void					affiche(t_tetri *tetri);
#endif
