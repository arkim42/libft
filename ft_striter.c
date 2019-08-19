/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:42:05 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:44:00 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applies the function f to each character of the string passed as argument.
**	Each character is passed by address to f to be modified if necessary.
**	Param. #1 : The string to iterate.
**	Param. #2 : The function to apply to each character of s.
*/

void				ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
