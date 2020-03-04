/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:37:23 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pr(char *str, t_printf *p)
{
	if (p->mn && p->zch)
		ft_putchar_pr(0, p);
	if (str)
		while (*str)
			ft_putchar_pr(*str++, p);
	if (!p->mn && p->zch)
		ft_putchar_pr(0, p);
}
