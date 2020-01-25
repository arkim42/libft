/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:27:05 by arkim             #+#    #+#             */
/*   Updated: 2020/01/24 22:19:17 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				pf_put_int(uint64_t n, t_pf *p)
{
	const char		hex_u[] = "0123456789ABCDEF";
	const char		hex_l[] = "0123456789abcdef";

	if (n >= (uint64_t)p->base)
		pf_put_int(n / p->base, p);
	(p->c & C_UPCASE) ? write(p->fd, &hex_u[n % p->base], 1) :\
					write(p->fd, &hex_l[n % p->base], 1);
}

static void			pf_put_dbl_1(uint64_t n, long double m, int len, t_pf *p)
{
	int				nbrlen;

	m *= ft_pow(p->base, len + 1);
	m = ((uint64_t)m % 10 >= 5) ? (m / 10 + 1) : (m / 10);
	if (pf_nbrlen((uint64_t)m, p) == (len + 1))
	{
		n++;
		m = 0;
	}
	pf_put_int(n, p);
	write(p->fd, ".", 1);
	nbrlen = pf_nbrlen(m, p);
	(nbrlen < len) ? ft_nputchar_fd('0', len - nbrlen, p->fd) \
							: write(p->fd, "", 0);
	pf_put_int(m, p);
}

static void			pf_put_dbl_2(uint64_t n, long double m, int len, t_pf *p)
{
	int				nbrlen;

	m *= ft_pow(p->base, 18);
	if (pf_nbrlen((uint64_t)m, p) == (18 + 1))
	{
		n++;
		m = 0;
	}
	pf_put_int(n, p);
	write(p->fd, ".", 1);
	nbrlen = pf_nbrlen(m, p);
	if (nbrlen < 18)
		ft_nputchar_fd('0', 18 - nbrlen, p->fd);
	pf_put_int(m, p);
	m -= (uint64_t)m;
	m *= ft_pow(p->base, len - 17);
	m = ((uint64_t)m % 10 >= 5) ? (m / 10 + 1) : (m / 10);
	nbrlen = pf_nbrlen(m, p);
	(nbrlen < (len - 18)) ? ft_nputchar_fd('0', len - 18 - nbrlen, p->fd) \
							: write(p->fd, "", 0);
	pf_put_int(m, p);
}

void				pf_put_dbl(long double n, t_pf *p)
{
	long double		decimal;
	int				len;
	uint64_t		mantissa;

	len = p->prec_w;
	n = (n < 0) ? -n : n;
	mantissa = (uint64_t)n;
	decimal = (long double)(n - mantissa);
	if (len > 0 && len < 19)
		pf_put_dbl_1(mantissa, decimal, len, p);
	else if (len >= 19)
		pf_put_dbl_2(mantissa, decimal, len, p);
	else if (len == 0)
	{
		decimal *= 10;
		mantissa = ((uint64_t)decimal % 10 >= 5) ? (mantissa + 1) : mantissa;
		pf_put_int(mantissa, p);
		(p->f & F_HASH) ? write(p->fd, ".", 1) : write(p->fd, "", 0);
	}
}

void				pf_put_scinum(long double n, t_pf *p)
{
	long double		decimal;
	int				i;

	decimal = (n < 0) ? -n : n;
	i = 0;
	while (!(decimal >= 1 && decimal < 10) && decimal)
	{
		(decimal >= 10) ? (decimal /= 10) : (decimal *= 10);
		i++;
	}
	pf_put_dbl(decimal, p);
	if (p->c & C_E)
		(p->c & C_UPCASE) ? write(p->fd, "E", 1) : write(p->fd, "e", 1);
	(ft_abs(n) >= 10 || !decimal) ? write(p->fd, "+", 1) : write(p->fd, "-", 1);
	(i < 10) ? write(p->fd, "0", 1) : write(p->fd, "", 0);
	ft_putnbr(i);
	p->len += 4;
}
