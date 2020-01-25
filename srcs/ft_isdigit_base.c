/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 03:21:19 by arkim             #+#    #+#             */
/*   Updated: 2019/09/08 03:27:06 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isdigit_base(char c, int base)
{
	const char	hex[] = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (hex[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}
