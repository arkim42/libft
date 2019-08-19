/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:53:23 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:41:48 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns a “fresh” string ending with ’\0’. Each character
**	of the string is initialized at ’\0’. If the allocation fails the function
**	returns NULL.
**	Param. #1 : The size of the string to be allocated.
*/

char				*ft_strnew(size_t size)
{
	char	*res;

	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	res[size] = '\0';
	while (size--)
		res[size] = '\0';
	return (res);
}
