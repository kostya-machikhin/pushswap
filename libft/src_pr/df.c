/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   df.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:54:59 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_float(t_printf *p, char c)
{
	if (c && (!p->ze || (p->ze && p->pr != -1)))
		addflag_o(p, c);
	else if (c && p->ze)
	{
		p->len--;
		p->el.s = length(p);
		addflag_o(p, c);
		return ;
	}
	p->el.s = length(p);
}

void	rounding(char *num)
{
	if (*num == '9')
	{
		*num = '0';
		rounding(num - 1);
	}
	else
		*num += 1;
}

char	*itoa_float(t_printf *p)
{
	char			*num;
	int				i;
	long double		nb;

	nb = p->el.ld;
	i = 0;
	p->pr == -1 ? p->pr = 6 : 0;
	nb -= (unsigned long long)p->el.ld;
	num = ft_strnew(sizeof(char) * (p->pr + 1));
	num[i] = '0';
	while (p->pr-- > 0)
	{
		nb -= (int)nb;
		nb *= 10;
		num[++i] = ((int)nb % 10) + '0';
	}
	nb -= (int)nb;
	nb *= 10;
	if ((int)nb % 10 >= 5 ||
	nb == 4.999999997968185283525599515996873378753662109375L)
		rounding(&num[i]);
	return (num);
}

void	parsefloat(t_printf *p)
{
	char c;
	char *flt;
	char *intgr;

	c = 0;
	if (p->fl)
		p->el.ld = va_arg(p->ap, long double);
	else
		p->el.ld = va_arg(p->ap, double);
	if (p->el.ld < 0)
	{
		p->el.ld *= -1;
		c = '-';
	}
	else if (p->pl || p->sp)
		c = (p->pl ? '+' : ' ');
	flt = itoa_float(p);
	flt[0] == '1' ? ++p->el.ld : 0;
	flt[0] = (ft_strlen(flt) != 1 || p->la) ? '.' : '\0';
	intgr = ft_itoa_base(p->el.ld, 10, 's');
	p->el.s = ft_strjoin(intgr, flt);
	free(flt);
	free(intgr);
	p_float(p, c);
}
