/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 21:57:03 by arkim             #+#    #+#             */
/*   Updated: 2020/01/24 22:36:51 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
