/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:45 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checklength(char c)
{
	char *nums;

	nums = "123456789";
	while (*nums)
		if (c == *nums++)
			return (1);
	return (0);
}

int		checkflag(char c)
{
	char *flags;

	flags = "cspdiouxXf";
	while (*flags)
		if (c == *flags++)
			return (1);
	return (0);
}

int		checkadflag(char c)
{
	char *flags;

	flags = ".Lhl#0123456789-+ ";
	while (*flags)
		if (c == *flags++)
			return (1);
	return (0);
}
