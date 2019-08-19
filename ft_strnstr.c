/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:31:52 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:22:40 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strnstr() function locates the first occurrence of the null-terminated
**	string needle in the string haystack, where not more than len characters are
**	searched. Characters that appear after a `\0' character are not searched.
**	Since the strnstr() function is a FreeBSD specific API, it should only be
**	used when portability is not a concern.
*/

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	int		i;

	n = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && n < len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (*(haystack + i) && *(needle + i)
					&& *(haystack + i) == *(needle + i))
				i++;
			if (!(*(needle + i)) && (n + i) <= len)
				return ((char *)haystack);
		}
		haystack++;
		n++;
	}
	return (0);
}
