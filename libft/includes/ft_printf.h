/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:59:46 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define RESET "\e[39m"
# define BGRED "\e[41m"
# define BGGREEN "\e[42m"
# define BGYELLOW "\e[43m"
# define BGBLUE "\e[44m"
# define BGRESET "\e[49m"
# define SIZE_COLOR 5

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef union	u_union
{
	long double			ld;
	long long int		ll;
	char				*s;
}				t_union;

typedef struct	s_printf
{
	t_union			el;
	va_list			ap;
	char			*f;
	int				len;
	int				pr;
	int				rtrn;
	unsigned char	fl : 1;
	unsigned char	l : 1;
	unsigned char	ll : 1;
	unsigned char	h : 1;
	unsigned char	hh : 1;
	unsigned char	la : 1;
	unsigned char	ze : 1;
	unsigned char	mn : 1;
	unsigned char	pl : 1;
	unsigned char	sp : 1;
	unsigned char	zch : 1;
}				t_printf;

int				parseflags(t_printf *p);
int				addflags(t_printf *p);
void			addsize(t_printf *p);
int				ordflags(t_printf *p);
int				checklength(char c);
int				checkflag(char c);
int				checkadflag(char c);
void			parsechar(t_printf *p);
void			parsestr(t_printf *p);
void			parseadr(t_printf *p);
void			parseint(t_printf *p);
int				p_int(t_printf *p);
void			parseoct(t_printf *p);
void			parseuns(t_printf *p);
void			parsecolor(t_printf *p);
void			p_color(t_printf *p, char *color, int size);
int				parseprc(t_printf *p);
void			parsehex(t_printf *p, char size);
t_printf		*zeroparseflag(t_printf *p);
int				ft_printf(const char *format, ...);
void			ft_putstr_pr(char *str, t_printf *p);
void			ft_putchar_pr(char c, t_printf *p);
char			*ft_itoa_base(unsigned long long nb, int base, char sl);
int				ft_atoi_pr(char **str);
void			hhll(t_printf *p);
void			uhhll(t_printf *p);
void			addflag_o(t_printf *p, char c);
void			addflag_t(t_printf *p, char size);
char			*length(t_printf *p);
char			*precstr(t_printf *p);
char			*precint(t_printf *p);
void			zerostruct(t_printf *p);
void			parsefloat(t_printf *p);
void			p_float(t_printf *p, char c);
char			*itoa_float(t_printf *p);
void			rounding(char *num);

#endif
