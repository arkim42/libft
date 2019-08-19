/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:34:42 by arkim             #+#    #+#             */
/*   Updated: 2019/08/11 03:46:21 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns a “fresh” string end- ing with ’\0’, result of the
**	concatenation of s1 and s2. If the allocation fails the function returns
**	NULL.
**	Param. #1 : The prefix string.
**	Param. #2 : The suffix string.
*/

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strncpy(res, s1, ft_strlen(s1));
	ft_strcpy(res + ft_strlen(s1), s2);
	return (res);
}
