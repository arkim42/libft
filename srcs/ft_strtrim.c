/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:21:16 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:23:13 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns a copy of the string given as argument without
**	whitespaces at the beginning or at the end of the string. Will be considered
**	as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s has no
**	whitespaces at the beginning or at the end, the function returns a copy of
**	s. If the allocation fails the function returns NULL.
**	Param. #1 : The string to be trimed.
*/

char				*ft_strtrim(char const *s)
{
	char		*res;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] && ft_iswspace3(s[i]))
		i++;
	while (i != len && ft_iswspace3(s[len - j - 1]))
		j++;
	if (!(res = ft_strnew(len - i - j)))
		return (NULL);
	ft_strncpy(res, s + i, len - i - j);
	return (res);
}
