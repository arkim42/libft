/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:57:32 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:38:18 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes as a parameter a link’s pointer address and frees the memory of the
**	link’s content using the function del given as a parameter, then frees the
**	link’s memory using free. The memory of next must not be freed under any
**	circumstance. Finally, the pointer to the link that was just freed must be
**	set to NULL (quite similar to the function ft_memdel in the mandatory part).
**	Param. #1 : The adress of a pointer to a link that needs to be freed.
*/

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
