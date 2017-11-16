/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 01:38:47 by hmartzol          #+#    #+#             */
/*   Updated: 2016/02/10 04:41:01 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef union	u_piece
{
	unsigned char		c[4];
	unsigned long int	i;
}				t_piece;

void			error(void);
void			solve(t_piece pieces[26], int pcount);

#endif
