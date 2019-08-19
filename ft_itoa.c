/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:40:37 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:53:53 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocate and returns a “fresh” string ending with ’\0’ representing the
**	integer n given as argument. Negative numbers must be supported. If the
**	allocation fails, the function returns NULL.
**	Param. #1 : The integer to be transformed into a string.
*/

char				*ft_itoa(int n)
{
	int				len;
	unsigned int	tmp;
	char			*res;

	len = ft_nbrlen(n);
	if (n < 0)
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	tmp = ft_abs(n);
	while (tmp)
	{
		res[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n == 0)
		res[0] = '0';
	return (res);
}
