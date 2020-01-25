/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:12:22 by arkim             #+#    #+#             */
/*   Updated: 2019/10/22 21:06:14 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strappend(char const *s1, char const *s2, int n1, int n2)
{
	char		*res;

	res = ft_strjoin(s1, s2);
	if (n1 && s1)
		free((void *)s1);
	if (n2 && s2)
		free((void *)s2);
	return (res);
}
