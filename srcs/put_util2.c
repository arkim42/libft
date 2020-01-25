/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:18:13 by arkim             #+#    #+#             */
/*   Updated: 2020/01/24 22:20:53 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char			*g_color[10] =
{
	"black",
	"red",
	"green",
	"yellow",
	"blue",
	"magenta",
	"cyan",
	"white",
	"default",
	"eoc"
};

const char			*g_color_code[10] =
{
	"\x1B[30m",
	"\x1B[31m",
	"\x1B[32m",
	"\x1B[33m",
	"\x1B[34m",
	"\x1B[35m",
	"\x1B[36m",
	"\x1B[37m",
	"\x1B[39m",
	"\033[0m"
};

void				pf_put_char(t_pf *p)
{
	unsigned char	c;
	int				padding;

	padding = ft_max(p->w - 1, 0);
	if (!(p->f & F_MINUS) && padding > 0)
		(p->f & F_ZERO) ? ft_nputchar_fd('0', padding, p->fd) \
							: ft_nputchar_fd(' ', padding, p->fd);
	c = (p->c & C_PER) ? '%' : (unsigned char)va_arg(p->ap, int);
	write(p->fd, &c, 1);
	if (p->f & F_MINUS && padding > 0)
		ft_nputchar_fd(' ', padding, p->fd);
	p->len += ft_max(p->w, 1);
}

void				pf_put_str(t_pf *p)
{
	char			*str;
	int				padding;
	int				len;

	str = (char *)va_arg(p->ap, int *);
	if (!str)
		str = STR_NULL;
	if (!ft_strcmp(str, ""))
		str = "";
	len = (int)ft_strlen(str);
	p->cur_len = (p->f & F_PREC) ? ft_min(p->prec_w, len) : len;
	padding = ft_max(p->w - p->cur_len, 0);
	if (!(p->f & F_MINUS) && padding > 0)
		(p->f & F_ZERO) ? ft_nputchar_fd('0', padding, p->fd) \
							: ft_nputchar_fd(' ', padding, p->fd);
	write(p->fd, str, p->cur_len);
	if (p->f & F_MINUS && padding > 0)
		ft_nputchar_fd(' ', padding, p->fd);
	p->len += p->cur_len + padding;
}

void				pf_put_ptraddr(t_pf *p)
{
	uint64_t		n;

	n = (uint64_t)va_arg(p->ap, void*);
	p->cur_len = pf_nbrlen(n, p);
	p->f |= F_HASH;
	p->c |= C_X;
	pf_numbers(p, n);
}

void				pf_put_color(t_pf *p)
{
	int				len;
	int				tmp;
	int				i;

	++p->fmt;
	len = ft_strchr_idx(p->fmt, '}');
	i = 0;
	while (i < 10)
	{
		if (!ft_strncmp(g_color[i], p->fmt, len))
		{
			tmp = ft_strlen(g_color_code[i]);
			write(p->fd, g_color_code[i], tmp);
			p->len += tmp;
			p->fmt += (len + 1);
			break ;
		}
		i++;
	}
	if (i == 10)
		--p->fmt;
}
