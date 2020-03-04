/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:36:24 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long nb, int base, char sl)
{
	unsigned long long	size;
	char				*str;
	unsigned long long	f;
	char				*tab;

	tab = "0123456789ABCDEF";
	if (sl == 's')
		tab = "0123456789abcdef";
	size = 0;
	f = nb;
	if (base < 0 || base > 16)
		return (0);
	while (f /= base)
		size++;
	str = (char *)ft_strnew(sizeof(char) * (++size));
	while (size-- > f)
	{
		str[size] = tab[nb % base];
		nb /= base;
	}
	return (str);
}
