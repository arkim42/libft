/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:54:15 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:37:40 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Iterates a list lst and applies the function f to each link to create a
**	“fresh” list resulting from the successive applications of f. If the
**	allocation fails, the function returns NULL.
**	Param. #1 : A pointer’s to the first link of a list.
**	Param. #2 : The address of a function to apply to each link of a list.
*/

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst || !(tmp = ft_lstnew(NULL, 0)))
		return (NULL);
	tmp = f(lst);
	res = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (res);
}
