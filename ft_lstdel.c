/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:56:01 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:38:05 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes as a parameter the adress of a pointer to a link and frees the memory
**	of this link and every successors of that link using the functions del and
**	free. Finally the pointer to the link that was just freed must be set to
**	NULL (quite similar to the function ft_memdel from the mandatory part).
**	Param. #1 : The address of a pointer to the first link of a list that needs
**	to be freed.
*/

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(&(*alst), del);
}
