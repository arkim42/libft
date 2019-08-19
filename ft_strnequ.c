/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:35:28 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:48:20 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Lexicographical comparison between s1 and s2 up to n characters or until a
**	’\0’ is reached. If the 2 strings are identical, the function returns 1,
**	or 0 otherwise.
**	Param. #1 : The first string to be compared.
**	Param. #2 : The second string to be compared.
**	Param. #3 : The maximum number of characters to be compared.
*/

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n-- && *s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}
