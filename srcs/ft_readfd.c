/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:46 by arkim             #+#    #+#             */
/*   Updated: 2019/10/22 16:02:47 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_readfd(int fd, char **file)
{
	int			ret;
	int			res;
	char		buff[MAX_FD + 1];

	if (!*file)
		*file = ft_strdup("");
	res = 0;
	while ((ret = read(fd, buff, MAX_FD)) > 0)
	{
		res += ret;
		buff[ret] = '\0';
		*file = ft_strappend(*file, buff, 1, 0);
	}
	if (ret < 0 && file)
	{
		res = ret;
		free(file);
		*file = NULL;
	}
	return (res);
}
