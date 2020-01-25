/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:47:42 by arkim             #+#    #+#             */
/*   Updated: 2019/08/29 21:50:13 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates and returns an array of “fresh” strings (all ending with ’\0’,
**	including the array itself) obtained by spliting s using the character c
**	as a delimiter. If the allocation fails the function returns NULL.
**	Param. #1 : The string to split.
**	Param. #2 : The delimiter character.
*/

#include <stdio.h>

char				**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		wc;
	int		i;
	int		j;

	if (!s)
		return (0);
	wc = ft_countword(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * wc + 1)))
		return (NULL);
	i = -1;
	while (i++ < wc)
	{
		j = ft_wordlen(s, c);
		while (*s && *s == c)
			s++;
		if (!(res[i] = ft_strnew(j)))
			return (NULL);
		ft_strncpy(res[i], s, j);
		s = s + j;
	}
	res[i - 1] = 0;
	return (res);
}
