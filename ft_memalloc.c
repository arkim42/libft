/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:02:23 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:39:39 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns a “fresh” memory area. The memory allocated is
**	initialized to 0. If the allocation fails, the function returns NULL.
**	Param. #1 : The size of the memory that needs to be allocated.
*/

void				*ft_memalloc(size_t size)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)malloc(size)))
		return (NULL);
	while (size--)
		res[size] = 0;
	return ((void *)res);
}
