/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:18:51 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:12:31 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applies the function f to each character of the string passed as argument by
**	giving its index as first argument to create a “fresh” new string resulting
**	from the successive applications of f.
**	Param. #1 : The string to map.
**	Param. #2 : The function to apply to each character of s and its index.
*/

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[len] = '\0';
	while (len--)
		res[len] = f(len, s[len]);
	return (res);
}
