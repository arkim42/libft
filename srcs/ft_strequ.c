/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:20:42 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:47:06 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Lexicographical comparison between s1 and s2. If the 2 strings are identical
**	the function returns 1, or 0 otherwise.
**	Param. #1 : The first string to be compared.
**	Param. #2 : The second string to be compared.
*/

int					ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	if (!*s1 && !*s2)
		return (1);
	return (0);
}
