/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:06:47 by yvillepo          #+#    #+#             */
/*   Updated: 2017/11/12 20:19:02 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;

	if (lst)
		new = f(lst);
	else
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstadd_next(new, f(lst));
		lst = lst->next;
	}
	new->next = NULL;
	return (head);
}
