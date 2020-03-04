/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionalf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:41:36 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*length(t_printf *p)
{
	int		dif;
	char	*s;
	char	c;

	c = ' ';
	if (p->ze && !p->mn && p->pr == -1)
		c = '0';
	s = 0;
	dif = p->len - ft_strlen(p->el.s);
	if (dif < 0)
		s = p->el.s;
	else
	{
		s = ft_strnew(sizeof(char) * p->len);
		ft_strcpy((p->mn ? s : s + dif), p->el.s);
		ft_memset((p->mn ? s + ft_strlen(p->el.s) : s), c, dif);
		free(p->el.s);
	}
	return (s);
}

char	*precstr(t_printf *p)
{
	char *s;

	s = 0;
	if (p->pr <= (int)ft_strlen(p->el.s) && p->pr != -1)
	{
		s = ft_strnew(sizeof(char) * p->pr);
		ft_strncpy(s, p->el.s, p->pr);
		free(p->el.s);
		return (s);
	}
	return (p->el.s);
}

char	*precint(t_printf *p)
{
	char	*s;
	int		dif;

	s = 0;
	dif = p->pr - ft_strlen(p->el.s);
	if (p->pr == 0 && !(ft_strlen(p->el.s) > 1 || p->el.s[0] != '0'))
	{
		free(p->el.s);
		p->el.s = ft_strnew(sizeof(char));
	}
	else if (p->pr >= (int)ft_strlen(p->el.s))
	{
		s = ft_strnew(sizeof(char) * p->pr);
		ft_memset(s, '0', dif);
		ft_strcpy(s + dif, p->el.s);
		free(p->el.s);
		return (s);
	}
	return (p->el.s);
}

void	addflag_o(t_printf *p, char c)
{
	char *s;

	s = ft_strnew(sizeof(char) * (ft_strlen(p->el.s) + 1));
	s[0] = c;
	ft_strcpy(s + 1, p->el.s);
	free(p->el.s);
	p->el.s = s;
}

void	addflag_t(t_printf *p, char size)
{
	char *s;

	s = ft_strnew(sizeof(char) * (ft_strlen(p->el.s) + 2));
	s[0] = '0';
	s[1] = (size == 's' ? 'x' : 'X');
	ft_strcpy(s + 2, p->el.s);
	free(p->el.s);
	p->el.s = s;
}
