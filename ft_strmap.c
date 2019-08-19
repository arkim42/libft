/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:48:34 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:45:32 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applies the function f to each character of the string given as argument to
**	create a “fresh” new string resulting from the successive applications of f.
**	Param. #1 : The string to map.
**	Param. #2 : The function to apply to each character of s.
*/

char				*ft_strmap(char const *s, char (*f)(char))
{
	char		*res;
	size_t		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
		res[len] = f(s[len]);
	return (res);
}
