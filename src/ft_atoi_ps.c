/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:08 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:08 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_ps(const char *str)
{
	unsigned long long	num;
	unsigned long long	maxval;
	unsigned long long	minval;
	int					sign;

	maxval = 9223372036854775807ULL;
	minval = 9223372036854775808ULL;
	sign = 1;
	num = 0;
	if (ft_strlen(str) > 11)
		return (10000000000);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*(str++) - '0');
	if ((num <= maxval && sign == 1) || (num <= minval && sign == -1))
		return (num * sign);
	return (sign == 1 ? -1 : 0);
}
