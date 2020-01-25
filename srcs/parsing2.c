/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:24:09 by arkim             #+#    #+#             */
/*   Updated: 2019/10/20 01:54:38 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(t_pf *p)
{
	++p->fmt;
	while (*p->fmt)
	{
		if (ft_iselem(*p->fmt, FLAGS))
			parse_flags(p);
		else if (ft_iselem(*p->fmt, "123456789"))
			parse_width(p);
		else if (ft_iselem(*p->fmt, "."))
			parse_precision(p);
		else if (ft_iselem(*p->fmt, LEN_MODIF))
			parse_length_modifier(p);
		else if (ft_iselem(ft_tolower(*p->fmt), CONV))
			break ;
		else
			return ;
	}
	parse_conversion(p);
}

void				pf_num_base(t_pf *p)
{
	if (p->c & (C_D | C_I | C_U))
		p->base = 10;
	if (p->c & (C_F | C_E | C_G))
	{
		p->base = 10;
		if (!(p->f & F_PREC))
			p->prec_w = 6;
	}
	else if (p->c & C_O)
		p->base = 8;
	else if (p->c & (C_X | C_A | C_P))
		p->base = 16;
	else if (p->c & C_B)
		p->base = 2;
}

void				ignoring(t_pf *p)
{
	if (p->f & F_HASH && !(p->c & (C_O | C_X | C_A | C_E | C_F | C_G | C_B)))
		p->f &= ~F_HASH;
	if (p->f & F_PREC && p->c & (C_INT | C_UINT))
		p->f &= ~F_ZERO;
	if (p->f & F_MINUS && p->f & F_ZERO)
		p->f &= ~F_ZERO;
	if (p->c & C_P)
		p->f &= ~(F_ZERO | F_PLUS | F_SPACE);
	if (p->c & C_UPCASE && p->c & (C_D | C_O | C_U))
		p->f |= F_L;
}

int					pf_nbrlen(int64_t n, t_pf *p)
{
	uint64_t		nbr;
	int				i;

	i = 1;
	nbr = (n < 0 && !(p->c & C_UINT)) ? -n : (uint64_t)n;
	while (nbr >= (uint64_t)p->base && i++)
		nbr /= p->base;
	return (i);
}

int					pf_dbllen(long double n, t_pf *p)
{
	int				i;
	long double		decimal;

	n = (n < 0) ? -n : n;
	i = pf_nbrlen((uint64_t)n, p);
	decimal = n - (uint64_t)n;
	return (i);
}
