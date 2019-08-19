/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:32:24 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:37:08 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns a “fresh” link. The variables content and content_size
**	of the new link are initialized by copy of the parameters of the function.
**	If the parameter content is nul, the variable content is initialized to NULL
**	and the variable content_size is initialized to 0 even if the parameter
**	content_size isn’t. The variable next is initialized to NULL. If the
**	allocation fails, the function returns NULL.
**	Param. #1 : The content to put in the new link.
**	Param. #2 : The size of the content of the new link.
*/

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(res->content = (void *)malloc(content_size)))
		{
			free(res);
			return (NULL);
		}
		ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
