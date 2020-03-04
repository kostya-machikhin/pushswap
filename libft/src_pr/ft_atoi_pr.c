/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:36:04 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_pr(char **str)
{
	unsigned long long	num;
	unsigned long long	maxval;
	unsigned long long	minval;
	int					sign;

	maxval = 9223372036854775807ULL;
	minval = 9223372036854775808ULL;
	sign = 1;
	num = 0;
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
		num = num * 10 + (*((*str)++) - '0');
	(*str)--;
	if ((num <= maxval && sign == 1) || (num <= minval && sign == -1))
		return (num * sign);
	return (sign == 1 ? -1 : 0);
}
