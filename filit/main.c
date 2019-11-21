/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:28 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/21 14:06:29 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_tetri			*tetri_list;
	unsigned int	nb_tetri;
	t_map			*map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	else if (argc == 2)
	{
		tetri_list = new_tetri();
		nb_tetri = read_input(argv[1], tetri_list);
		tetri_list = tetri_list->next;
		if (!tetri_connect(tetri_list))
		{
			error();
			return (1);
		}
		map = solve(tetri_list, nb_tetri);
		print_map(map);
		free_map(map);
	}
	return (0);
}
