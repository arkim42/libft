/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:14:08 by arkim             #+#    #+#             */
/*   Updated: 2020/01/24 22:17:48 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		make_line(char **res, char **line)
{
	int			len;
	char		*tmp;

	len = 0;
	while ((*res)[len] && (*res)[len] != '\n')
		len++;
	*line = ft_strsub(*res, 0, len);
	if (((*res)[len] && !(*res)[len + 1]) || !(*res)[len])
		ft_strdel(res);
	else
	{
		tmp = ft_strdup(*res + len + 1);
		free(*res);
		*res = tmp;
	}
}

int				get_next_line(const int fd, char **line)
{
	int			size;
	static char	*res[MAX_FD];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || fd > MAX_FD || read(fd, buff, 0) < 0)
		return (-1);
	if (!res[fd])
		res[fd] = ft_strnew(1);
	size = 1;
	while (!ft_strchr(res[fd], '\n') && size != 0)
	{
		if ((size = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		buff[size] = '\0';
		res[fd] = ft_strappend(res[fd], buff, 1, 0);
		if (size == 0 && res[fd][0] == '\0')
			return (0);
	}
	make_line(&res[fd], line);
	return (1);
}
