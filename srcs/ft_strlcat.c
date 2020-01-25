/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:42:52 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:10:54 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	strlcat() functions copy and concatenate strings
**	with the same input parameters and output result as snprintf(3).
**	They are designed to be safer, more consistent, and less error prone
**	replacements for the easily misused functions strncpy(3) and
**	strncat(3).
**	strlcat() appends string src to the end of dst.  It will append at
**	most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
**	unless dstsize is 0 or the original dst string was longer than
**	dstsize (in practice this should not happen as it means that either
**	dstsize is incorrect or that dst is not a proper string).
*/

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	if (dstsize < len)
		return (ft_strlen(src) + dstsize);
	while (src[i] != '\0' && (len + i) < (dstsize - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
