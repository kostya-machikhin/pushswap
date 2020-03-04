/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:50:32 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parseint(t_printf *p)
{
	char c;

	c = 0;
	hhll(p);
	if (p->el.ll != -9223372036854775807ll - 1)
	{
		if (!p_int(p))
			return ;
	}
	else
	{
		p->el.s = ft_strnew(sizeof(char) * 20);
		ft_strcpy(p->el.s, "-9223372036854775808");
	}
	p->el.s = length(p);
}

void	parseoct(t_printf *p)
{
	uhhll(p);
	p->el.s = ft_itoa_base(p->el.ll, 8, 's');
	p->el.s = precint(p);
	if (p->la && p->el.s[0] != '0')
		addflag_o(p, '0');
	p->el.s = length(p);
}

void	parseuns(t_printf *p)
{
	uhhll(p);
	p->el.s = ft_itoa_base(p->el.ll, 10, 's');
	p->el.s = precint(p);
	p->el.s = length(p);
}

void	parsehex(t_printf *p, char size)
{
	int zero;

	uhhll(p);
	p->el.s = ft_itoa_base(p->el.ll, 16, size);
	zero = (ft_strlen(p->el.s) == 1 && p->el.s[0] == '0');
	p->el.s = precint(p);
	if (!zero && p->la)
	{
		if (p->ze && p->pr == -1)
		{
			p->len -= 2;
			p->el.s = length(p);
			addflag_t(p, size);
			return ;
		}
		addflag_t(p, size);
	}
	p->el.s = length(p);
}
