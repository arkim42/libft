/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:57:46 by arkim             #+#    #+#             */
/*   Updated: 2019/10/22 18:43:32 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puterror(char const *error_msg)
{
	if (error_msg == NULL)
		return ;
	write(1, error_msg, ft_strlen(error_msg));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
