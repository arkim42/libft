/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:34:45 by arkim             #+#    #+#             */
/*   Updated: 2019/09/26 22:01:28 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base(int n, unsigned int base)
{
	int				len;
	unsigned int	tmp;
	char			*res;
	const char		hex[] = "0123456789ABCDEF";

	len = ft_nbrlen_base(n, base);
	if (n < 0 && base == 10)
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[len] = '\0';
	if (n < 0 && base == 10)
		res[0] = '-';
	tmp = ft_abs(n);
	while (tmp)
	{
		res[--len] = hex[tmp % base];
		tmp /= base;
	}
	if (n == 0)
		res[0] = '0';
	return (res);
}
