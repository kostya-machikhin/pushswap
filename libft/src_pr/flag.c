/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:35:35 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		addflags(t_printf *p)
{
	if (checklength(*p->f))
		p->len = ft_atoi_pr(&p->f);
	else if (*p->f == '0')
		p->ze = 1;
	else if (*p->f == '#')
		p->la = 1;
	else if (*p->f == '-')
		p->mn = 1;
	else if (*p->f == '+')
		p->pl = 1;
	else if (*p->f == ' ')
		p->sp = 1;
	else if (*p->f == '.')
	{
		p->f++;
		p->pr = ft_atoi_pr(&p->f);
	}
	else
		return (0);
	return (1);
}

void	addsize(t_printf *p)
{
	p->h = 0;
	p->hh = 0;
	p->l = 0;
	p->ll = 0;
	p->fl = 0;
	if (*p->f == 'l' && *(p->f + 1) != 'l')
		p->l = 1;
	else if (*p->f == 'l' && *(p->f + 1) == 'l')
	{
		p->f++;
		p->ll = 1;
	}
	else if (*p->f == 'h' && *(p->f + 1) != 'h')
		p->h = 1;
	else if (*p->f == 'h' && *(p->f + 1) == 'h')
	{
		p->f++;
		p->hh = 1;
	}
	else if (*p->f == 'L')
		p->fl = 1;
}

int		ordflags(t_printf *p)
{
	*p->f == 'c' ? parsechar(p) : 0;
	*p->f == 's' ? parsestr(p) : 0;
	*p->f == 'p' ? parseadr(p) : 0;
	*p->f == 'd' || *(p->f) == 'i' ? parseint(p) : 0;
	*p->f == 'o' ? parseoct(p) : 0;
	*p->f == 'u' ? parseuns(p) : 0;
	*p->f == 'x' ? parsehex(p, 's') : 0;
	*p->f == 'X' ? parsehex(p, 'b') : 0;
	*p->f == 'f' ? parsefloat(p) : 0;
	return (1);
}
