/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:47:35 by arkim             #+#    #+#             */
/*   Updated: 2019/08/08 01:29:37 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Adds the element new at the beginning of the list.
**	Param. #1 : The address of a pointer to the first link of a list.
**	Param. #2 : The link to add at the beginning of the list.
*/

void				ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
