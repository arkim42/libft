/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 23:24:43 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:07:43 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The strstr() function locates the first occurrence of the null-terminated
**	string needle in the null-terminated string haystack.
*/

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (*(haystack + i) && *(needle + i)
					&& *(haystack + i) == *(needle + i))
				i++;
			if (!(*(needle + i)))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
