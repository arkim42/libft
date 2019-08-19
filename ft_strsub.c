/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:37:41 by arkim             #+#    #+#             */
/*   Updated: 2019/08/10 00:49:19 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns a “fresh” substring from the string given as argument.
**	The substring begins at indexstart and is of size len. If start and len
**	aren’t refer- ing to a valid substring, the behavior is undefined. If the
**	allocation fails, the function returns NULL.
**	Param. #1 : The string from which create the substring.
**	Param. #2 : The start index of the substring.
**	Param. #3 : The size of the substring.
*/

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
		res[len] = s[start + len];
	return (res);
}
