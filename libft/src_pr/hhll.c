/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hhll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:40:52 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hhll(t_printf *p)
{
	if (p->ll)
		p->el.ll = va_arg(p->ap, long long int);
	else if (p->l)
		p->el.ll = va_arg(p->ap, long int);
	else if (p->h)
		p->el.ll = (short)va_arg(p->ap, int);
	else if (p->hh)
		p->el.ll = (char)va_arg(p->ap, int);
	else
		p->el.ll = va_arg(p->ap, int);
}

void	uhhll(t_printf *p)
{
	if (p->ll)
		p->el.ll = va_arg(p->ap, unsigned long long int);
	else if (p->l)
		p->el.ll = va_arg(p->ap, unsigned long int);
	else if (p->h)
		p->el.ll = (unsigned short)va_arg(p->ap, unsigned int);
	else if (p->hh)
		p->el.ll = (unsigned char)va_arg(p->ap, unsigned int);
	else
		p->el.ll = va_arg(p->ap, unsigned int);
}
