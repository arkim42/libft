/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:12:29 by arkim             #+#    #+#             */
/*   Updated: 2019/10/20 01:41:23 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	t_pf			p;

	ft_bzero(&p, sizeof(p));
	p.fd = 1;
	p.fmt = (char *)format;
	va_start(p.ap, format);
	while (*p.fmt)
	{
		if (*p.fmt == '{')
			pf_put_color(&p);
		if (*p.fmt == '%' && *(p.fmt + 1) == '%' && ++p.len && (p.fmt += 2))
			write(p.fd, "%", 1);
		else if (*p.fmt == '%')
		{
			parsing(&p);
			if (p.c)
				sorting(&p);
		}
		else if (*p.fmt && ++p.len)
			write(p.fd, p.fmt++, 1);
		reset_pf(&p);
	}
	va_end(p.ap);
	return (p.len);
}

void				reset_pf(t_pf *p)
{
	p->f = 0;
	p->c = 0;
	p->w = 0;
	p->prec_w = 0;
	p->base = 0;
	p->cur_len = 0;
}
