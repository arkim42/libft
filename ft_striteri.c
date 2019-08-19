/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:45:17 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:44:40 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applies the function f to each character of the string passed as argument,
**	and passing its index as first argument. Each character is passed by address
**	to f to be modified if necessary.
**	Param. #1 : The string to iterate.
**	Param. #2 : The function to apply to each character of s and its index.
*/

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;

	idx = 0;
	if (s && f)
		while (*s)
			f(idx++, s++);
}
