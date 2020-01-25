/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:36:53 by arkim             #+#    #+#             */
/*   Updated: 2019/10/20 01:21:31 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				sorting(t_pf *p)
{
	if (p->f & F_HASH && !(p->c & (C_O | C_X | C_A | C_E | C_F | C_G | C_B)))
		p->f &= ~F_HASH;
	if ((p->f & F_PREC && p->c & (C_INT | C_UINT)) \
		|| (p->f & F_MINUS && p->f & F_ZERO))
		p->f &= ~F_ZERO;
	if (p->c & C_P)
		p->f &= ~(F_ZERO | F_PLUS | F_SPACE);
	if (p->c & C_UPCASE && p->c & (C_D | C_O | C_U))
		p->f |= F_L;
	if (!(p->c) && ++p->fmt)
		return ;
	else if (p->c & (C_PER | C_C))
		pf_put_char(p);
	else if (p->c & (C_D | C_I))
		sort_int(p);
	else if (p->c & (C_O | C_U | C_X | C_B))
		sort_uint(p);
	else if (p->c & (C_F | C_E | C_G))
		sort_dbl(p);
	else if (p->c & C_S)
		pf_put_str(p);
	else if (p->c & C_P)
		pf_put_ptraddr(p);
}

void				sort_int(t_pf *p)
{
	int64_t			n;

	n = 0;
	if (p->f & F_LL)
		n = va_arg(p->ap, long long);
	else if (p->f & F_L)
		n = va_arg(p->ap, long);
	else if (p->f & F_J)
		n = va_arg(p->ap, intmax_t);
	else if (p->f & F_Z)
		n = va_arg(p->ap, ssize_t);
	else if (!(p->f >> 11))
		n = va_arg(p->ap, int);
	else if (p->f & F_H)
		n = ((short)va_arg(p->ap, int));
	else if (p->f & F_HH)
		n = ((char)va_arg(p->ap, int));
	p->cur_len = pf_nbrlen(n, p);
	pf_numbers(p, n);
}

void				sort_uint(t_pf *p)
{
	uint64_t		n;

	n = 0;
	if (p->f & F_LL)
		n = va_arg(p->ap, unsigned long long);
	else if (p->f & F_L)
		n = va_arg(p->ap, unsigned long);
	else if (p->f & F_J)
		n = va_arg(p->ap, uintmax_t);
	else if (p->f & F_Z)
		n = va_arg(p->ap, size_t);
	else if (!(p->f >> 11))
		n = va_arg(p->ap, unsigned int);
	else if (p->f & F_H)
		n = ((unsigned short)va_arg(p->ap, unsigned int));
	else if (p->f & F_HH)
		n = ((unsigned char)va_arg(p->ap, unsigned int));
	p->cur_len = pf_nbrlen(n, p);
	pf_numbers(p, n);
}

void				sort_dbl(t_pf *p)
{
	long double		n;

	n = 0;
	if (p->f & F_UL)
		n = (long double)va_arg(p->ap, long double);
	else if (p->f & (F_HH | F_H | F_L | F_LL | F_J) || !(p->f >> 10))
		n = (long double)va_arg(p->ap, double);
	p->cur_len = (p->c & (C_E | C_A)) ? 1 : pf_dbllen(n, p);
	pf_doubles(p, n);
}
