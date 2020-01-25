/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:10:41 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:18:21 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to be n bytes long.
*/

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n && *(unsigned char *)s1++ == *(unsigned char *)s2++)
		--n;
	if (n == 0)
		return (0);
	return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
}
