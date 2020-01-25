/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:37:31 by arkim             #+#    #+#             */
/*   Updated: 2019/09/26 21:48:12 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_nbrlen_base(int n, unsigned int base)
{
	unsigned int	nbr;
	int				i;

	i = 1;
	if (!(base >= 2 && base <= 16))
		base = 10;
	nbr = ft_abs(n);
	while (nbr >= base && i++)
		nbr /= base;
	return (i);
}
