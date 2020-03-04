/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:28:13 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zerostruct(t_printf *p)
{
	p->el.s = 0;
	p->el.ll = 0;
	p->len = 0;
	p->pr = -1;
	p->l = 0;
	p->ll = 0;
	p->la = 0;
	p->ze = 0;
	p->mn = 0;
	p->pl = 0;
	p->sp = 0;
	p->zch = 0;
	p->fl = 0;
}

t_printf	*zeroparseflag(t_printf *p)
{
	char *str;

	if (!(str = ft_strnew(sizeof(char))))
		return (p);
	str[0] = *p->f++;
	p->el.s = str;
	return (p);
}

int			parseprc(t_printf *p)
{
	char *str;

	str = 0;
	if (!(*(p->f + 1)))
		return (0);
	p->f++;
	if (parseflags(p))
	{
		p->f++;
		ft_putstr_pr((str = p->el.s), p);
		free(str);
	}
	else if (*p->f)
	{
		ft_putstr_pr((str = length(zeroparseflag(p))), p);
		free(str);
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_printf	p;

	p.len = 0;
	p.rtrn = 0;
	p.f = (char *)format;
	va_start(p.ap, format);
	while (*p.f)
	{
		zerostruct(&p);
		if (*p.f == '%')
		{
			if (!parseprc(&p))
				break ;
		}
		else if (*p.f == '{')
			parsecolor(&p);
		else
			ft_putchar_pr(*p.f++, &p);
	}
	return (p.rtrn);
}
