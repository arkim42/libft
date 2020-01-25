/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 00:13:52 by arkim             #+#    #+#             */
/*   Updated: 2020/01/24 22:18:40 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_sign_hash(int64_t n, t_pf *p)
{
	if (n < 0 && !(p->c & C_UINT))
		write(p->fd, "-", 1);
	else if (p->f & (F_PLUS | F_SPACE) && !(p->c & C_UINT))
		(p->f & F_PLUS) ? write(p->fd, "+", 1) : write(p->fd, " ", 1);
	if (p->f & F_HASH && p->prec_w <= p->cur_len && p->c & C_O)
		(!(p->f & F_PREC) & !n) ? write(p->fd, "", 0) : write(p->fd, "0", 1);
	if ((n && p->f & F_HASH && p->c & C_X) || p->c & C_P)
		(p->c & C_UPCASE && !(p->c & C_P)) ? write(p->fd, "0X", 2) \
											: write(p->fd, "0x", 2);
	if (n && p->f & F_HASH && p->c & C_B)
		(p->c & C_UPCASE) ? write(p->fd, "0B", 2) : write(p->fd, "0b", 2);
}

static void			pf_num_aux(t_pf *p, int64_t n, int *sign, int *padd)
{
	*sign = (!(p->c & C_UINT) && (p->f & (F_PLUS | F_SPACE) || n < 0)) ? 1 : 0;
	padd[2] = ((p->prec_w <= p->cur_len && p->f & F_HASH && p->c & C_O) \
																	? 1 : 0) \
		- ((p->f & F_HASH && !(p->f & F_PREC) && !n && p->c & C_O) ? 1 : 0) \
		+ (((n && p->f & F_HASH && p->c & (C_X | C_B)) || p->c & C_P) ? 2 : 0);
	padd[0] = ((p->prec_w > p->cur_len) ? (p->prec_w - p->cur_len) : 0);
	padd[1] = ((p->w > (ft_max(p->cur_len, p->prec_w))) ? \
			(p->w - (ft_max(p->cur_len, p->prec_w))) : 0) - *sign - padd[2];
}

void				pf_numbers(t_pf *p, int64_t n)
{
	uint64_t		nbr;
	int				sign;
	int				padd[3];

	padd[0] = 0;
	padd[1] = 0;
	padd[2] = 0;
	nbr = (n < 0 && !(p->c & C_UINT)) ? -n : (uint64_t)n;
	if (p->f & F_PREC && !nbr && !(p->prec_w))
		p->cur_len = 0;
	pf_num_aux(p, n, &sign, padd);
	if (!(p->f & F_MINUS) && padd[1] > 0 && !(p->f & F_ZERO))
		ft_nputchar_fd(' ', padd[1], p->fd);
	pf_sign_hash(n, p);
	if (padd[0] > 0 || (p->f & F_ZERO && !p->prec_w && padd[1] > 0))
		(padd[0] > 0) ? ft_nputchar_fd('0', padd[0], p->fd) \
						: ft_nputchar_fd('0', padd[1], p->fd);
	if (p->cur_len)
		pf_put_int(nbr, p);
	if (p->f & F_MINUS && padd[1] > 0)
		ft_nputchar_fd(' ', padd[1], p->fd);
	p->len += p->cur_len + ((padd[0] > 0) ? padd[0] : 0) \
				+ ((padd[1] > 0) ? padd[1] : 0) + sign + padd[2];
}

void				pf_doubles(t_pf *p, long double n)
{
	long double		nbr;
	int				padd;
	int				sign;
	int				dec_len;

	nbr = (n < 0) ? -n : n;
	sign = (p->f & (F_PLUS | F_SPACE) || n < 0) ? 1 : 0;
	dec_len = ((p->prec_w) ? p->prec_w : 0) \
			+ ((p->prec_w || p->f & F_HASH) ? 1 : 0);
	padd = ((p->w > p->cur_len) ? p->w - p->cur_len : 0) \
			- ((p->c & C_E) ? 4 : 0) - dec_len - sign;
	if (!(p->f & F_MINUS) && !(p->f & F_ZERO) && padd > 0)
		ft_nputchar_fd(' ', padd, p->fd);
	if (n < 0)
		write(p->fd, "-", 1);
	else if (p->f & (F_PLUS | F_SPACE))
		(p->f & F_PLUS) ? write(p->fd, "+", 1) : write(p->fd, " ", 1);
	if (p->f & F_ZERO && padd > 0)
		ft_nputchar_fd('0', padd, p->fd);
	if (p->cur_len && (p->c & (C_F | C_E)))
		(p->c & C_F) ? pf_put_dbl(nbr, p) : pf_put_scinum(nbr, p);
	if (p->f & F_MINUS && !(p->f & F_ZERO) && padd > 0)
		ft_nputchar_fd(' ', padd, p->fd);
	p->len += p->cur_len + dec_len + ((padd > 0) ? padd : 0) + sign;
}
