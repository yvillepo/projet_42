/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:36:28 by cpirlot           #+#    #+#             */
/*   Updated: 2017/11/19 17:41:17 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_tetri			*tetri_list;
	unsigned int	nb_tetri;
	int				i = 1;
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
		/*while(tetri_list)
		{
			affiche(tetri_list);
			ft_putchar('\n');
			tetri_list = tetri_list->next;
		}*/
		map = solve(tetri_list, nb_tetri);
		//printf("solution : \n");
		//print_map(map);	
		//printf("\n\n\n\n");
		//while(i--)
		//{
	//		ft_putchar(tetri_list->letter);
//			ft_putchar('\n');
//			tetri_list = tetri_list->next;
//		}
		/*
		while (i <= 25)
		{
			free(tetri_list[i].block_square);
			free(tetri_list);
		}
		free(tetri_list); */
	}
	return (0);
}
