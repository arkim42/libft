/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:16:42 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:19:27 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The memccpy() function copies bytes from string src to string dst.
**	If the character c (as converted to an unsigned char) occurs in the
**	string src, the copy stops and a pointer to the byte after the copy
**	of c in the string dst is returned.  Otherwise, n bytes are copied,
**	and a NULL pointer is returned.
**	The source and destination strings should not overlap, as the behav-
**	ior is undefined.
*/

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (src == dst)
		return (dst);
	else
		while (n--)
		{
			*d++ = *s;
			if (*s++ == (unsigned char)c)
				return (d);
		}
	return (0);
}
