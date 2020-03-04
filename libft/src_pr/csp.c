/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:35:12 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsechar(t_printf *p)
{
	char *str;

	str = 0;
	p->el.ll = (char)va_arg(p->ap, unsigned int);
	str = ft_strnew(sizeof(char));
	if (!p->el.ll)
	{
		p->zch++;
		p->len--;
	}
	str[0] = p->el.ll;
	p->el.s = str;
	p->el.s = length(p);
}

void	parsestr(t_printf *p)
{
	char *str;

	str = 0;
	p->el.s = va_arg(p->ap, void *);
	if (p->el.s)
	{
		str = ft_strnew(sizeof(char) * ft_strlen(p->el.s));
		ft_strcpy(str, p->el.s);
		p->el.s = str;
		p->el.s = precstr(p);
	}
	else
	{
		p->el.s = ft_strnew(sizeof(char) * 6);
		ft_strcpy(p->el.s, "(null)");
		p->el.s = precstr(p);
	}
	p->el.s = length(p);
}

void	parseadr(t_printf *p)
{
	p->el.ll = va_arg(p->ap, unsigned long);
	p->el.s = ft_itoa_base(p->el.ll, 16, 's');
	p->el.s = precint(p);
	addflag_t(p, 's');
	p->el.s = length(p);
}
