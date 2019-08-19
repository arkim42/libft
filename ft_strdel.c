/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:37:04 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 02:22:22 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes as a parameter the address of a string that need to be freed with
**	free, then sets its pointer to NULL.
**	Param. #1 : The string’s address that needs to be freed and its pointer set
**	to NULL.
*/

void				ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = 0;
	}
}
