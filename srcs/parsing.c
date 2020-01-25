/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:04:10 by arkim             #+#    #+#             */
/*   Updated: 2019/10/20 01:28:16 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(t_pf *p)
{
	int		tmp;

	while ((tmp = ft_strchr_idx(FLAGS, *p->fmt)) != -1 && *p->fmt)
	{
		p->f |= (1 << tmp);
		if (*p->fmt == '*')
		{
			p->w = (int)va_arg(p->ap, int);
			if (p->w < 0)
			{
				p->w = -p->w;
				p->f |= F_MINUS;
			}
		}
		p->fmt++;
	}
}

void		parse_width(t_pf *p)
{
	if (*p->fmt >= '1' && *p->fmt <= '9')
	{
		p->f |= F_WIDTH;
		p->w = ft_atoi(p->fmt);
		p->fmt += ft_nbrlen(p->w);
	}
}

void		parse_precision(t_pf *p)
{
	if (*p->fmt == '.')
	{
		p->f |= F_PREC;
		++p->fmt;
		p->prec_w = 0;
		if (*p->fmt >= '0' && *p->fmt <= '9')
		{
			p->prec_w = ft_atoi(p->fmt);
			while (*p->fmt >= '0' && *p->fmt <= '9')
				p->fmt++;
		}
		else if (*p->fmt == '*')
		{
			p->f |= F_PREC_STAR;
			if (p->f & F_PREC_STAR)
				p->prec_w = (int)va_arg(p->ap, int);
			if (p->prec_w < 0)
			{
				p->f &= ~F_PREC;
				p->prec_w = 0;
			}
			++p->fmt;
		}
	}
}

void		parse_length_modifier(t_pf *p)
{
	int		tmp;

	while ((tmp = ft_strchr_idx(LEN_MODIF, *p->fmt)) != -1 && *p->fmt)
	{
		p->f |= (1 << (tmp + 11));
		if (tmp == 0 && *(p->fmt + 1) == 'h')
		{
			p->f &= ~F_H;
			p->f |= F_HH;
			++p->fmt;
		}
		if (tmp == 1 && *(p->fmt + 1) == 'l')
		{
			p->f &= ~F_L;
			p->f |= F_LL;
			++p->fmt;
		}
		++p->fmt;
	}
}

void		parse_conversion(t_pf *p)
{
	int		tmp;

	if ((tmp = ft_strchr_idx(CONV, *p->fmt) + 1) && *p->fmt)
	{
		p->c |= (1 << tmp);
		p->fmt++;
	}
	else if ((tmp = ft_strchr_idx(CONV2, *p->fmt) + 1) && *p->fmt)
	{
		p->c |= C_UPCASE;
		p->c |= (1 << tmp);
		p->fmt++;
	}
	if (p->c)
		pf_num_base(p);
}
