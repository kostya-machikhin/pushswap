/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:43:36 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_int(t_printf *p)
{
	char c;

	c = 0;
	if (p->el.ll < 0)
		c = '-';
	else if (p->pl || p->sp)
		c = (p->pl ? '+' : ' ');
	p->el.s = (p->el.ll < 0 ? ft_itoa_base(-p->el.ll, 10, 's') :
			ft_itoa_base(p->el.ll, 10, 's'));
	p->el.s = precint(p);
	if (c && (!p->ze || (p->ze && p->pr != -1)))
		addflag_o(p, c);
	else if (c && p->ze)
	{
		p->len--;
		p->el.s = length(p);
		addflag_o(p, c);
		return (0);
	}
	return (1);
}
