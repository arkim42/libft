/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:05:14 by arkim             #+#    #+#             */
/*   Updated: 2020/01/24 22:07:39 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

# define STR_NULL			"(null)"

/*
**						specifier: flags
*/

# define FLAGS			"-+ 0#*$'"
# define F_MINUS		0x000001
# define F_PLUS			0x000002
# define F_SPACE		0x000004
# define F_ZERO			0x000008
# define F_HASH			0x000010
# define F_ASTERISK		0x000020
# define F_DOLLAR		0x000040
# define F_APOSTROPHE	0x000080

/*
**						specifier: length
*/

# define LEN_MODIF		"hljtzL"
# define F_H			0x000800
# define F_L			0x001000
# define F_J			0x002000
# define F_T			0x004000
# define F_Z			0x008000
# define F_UL			0x010000
# define F_HH			0x020000
# define F_LL			0x040000

/*
**						bonus
*/

# define F_WIDTH		0x000100
# define F_PREC			0x000200
# define F_PREC_STAR	0x000400

/*
**						CONV specifiers
*/

# define CONV			"diouxfegacspnbrk%"
# define CONV2			"DIOUXFEGACSPNBRK"
# define C_UPCASE		0x000001
# define C_D			0x000002
# define C_I			0x000004
# define C_O			0x000008
# define C_U			0x000010
# define C_X			0x000020
# define C_F			0x000040
# define C_E			0x000080
# define C_G			0x000100
# define C_A			0x000200
# define C_C			0x000400
# define C_S			0x000800
# define C_P			0x001000
# define C_N			0x002000
# define C_B			0x004000
# define C_R			0x008000
# define C_K			0x010000
# define C_PER			0x020000
# define C_INT			0x000006
# define C_UINT			0x004038

/*
**		fmt : format string		|	prec_w  : precision width
**		f   : flag				|	cur_len : current length
**		c   : conversiions		|	len		: cumulative length
**		w   : width				|	base    : base number
*/

typedef struct		s_printf
{
	char			*fmt;
	int				f;
	int				c;
	int				w;
	int				prec_w;
	int				cur_len;
	int				len;
	int				base;
	int				fd;
	va_list			ap;
}					t_pf;

/*
**					ft_printf.c
*/

int					ft_printf(const char *format, ...);
void				reset_pf(t_pf *p);

/*
**					parsing.c
*/

void				parse_flags(t_pf *p);
void				parse_width(t_pf *p);
void				parse_precision(t_pf *p);
void				parse_length_modifier(t_pf *p);
void				parse_conversion(t_pf *p);

/*
**					parsing2.c
*/

void				parsing(t_pf *p);
void				pf_num_base(t_pf *p);
void				ignoring(t_pf *p);
int					pf_nbrlen(int64_t n, t_pf *p);
int					pf_dbllen(long double n, t_pf *p);

/*
**					sorting.c
*/

void				sorting(t_pf *p);
void				sort_int(t_pf *p);
void				sort_uint(t_pf *p);
void				sort_dbl(t_pf *p);

/*
**					numbers.c
*/

void				pf_numbers(t_pf *p, int64_t n);
void				pf_doubles(t_pf *p, long double n);

/*
**					put_util.c
*/

void				pf_put_int(uint64_t n, t_pf *p);
void				pf_put_dbl(long double n, t_pf *p);
void				pf_put_scinum(long double n, t_pf *p);

/*
**					put_util2.c
*/

void				pf_put_char(t_pf *p);
void				pf_put_str(t_pf *p);
void				pf_put_ptraddr(t_pf *p);
void				pf_put_color(t_pf *p);

#endif
