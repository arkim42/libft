/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:33:57 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:43:18 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Sets every character of the string to the value ’\0’.
**	Param. #1 : The string that needs to be cleared.
*/

void				ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
