/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:39:03 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parseflags(t_printf *p)
{
	if (*p->f)
	{
		if (checkadflag(*p->f))
		{
			if (!addflags(p))
				addsize(p);
			if (*p->f)
				p->f++;
			return (parseflags(p));
		}
		else if (checkflag(*p->f))
			return (ordflags(p));
	}
	return (0);
}
