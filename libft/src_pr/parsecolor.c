/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:05:11 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		p_color(t_printf *p, char *color, int size)
{
	ft_putstr_pr(color, p);
	p->f += size;
	p->rtrn -= SIZE_COLOR;
}

void		parsecolor(t_printf *p)
{
	if (!ft_strncmp(p->f, "{RED}", 5))
		p_color(p, RED, 5);
	else if (!ft_strncmp(p->f, "{GREEN}", 7))
		p_color(p, GREEN, 7);
	else if (!ft_strncmp(p->f, "{YELLOW}", 8))
		p_color(p, YELLOW, 8);
	else if (!ft_strncmp(p->f, "{BLUE}", 6))
		p_color(p, BLUE, 6);
	else if (!ft_strncmp(p->f, "{RESET}", 7))
		p_color(p, RESET, 7);
	else if (!ft_strncmp(p->f, "{BGRED}", 7))
		p_color(p, BGRED, 7);
	else if (!ft_strncmp(p->f, "{BGGREEN}", 9))
		p_color(p, BGGREEN, 9);
	else if (!ft_strncmp(p->f, "{BGYELLOW}", 10))
		p_color(p, BGYELLOW, 10);
	else if (!ft_strncmp(p->f, "{BGBLUE}", 8))
		p_color(p, BGBLUE, 8);
	else if (!ft_strncmp(p->f, "{BGRESET}", 9))
		p_color(p, BGRESET, 9);
	else
		ft_putchar_pr(*p->f++, p);
}
