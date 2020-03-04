/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:10:44 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int size;

	size = (n >= 0 ? 1 : 2);
	n = (n >= 0 ? n : -n);
	while ((n = n / 10) > 0)
		size++;
	return (size);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		s;
	char	*tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = size(n);
	if (!(num = ft_strnew(sizeof(char) * s)))
		return (NULL);
	if (n < 0)
		*num = '-';
	n = (n >= 0 ? n : -n);
	tmp = num;
	while (s--)
		tmp++;
	tmp--;
	while (n >= 10)
	{
		*tmp-- = (n % 10) + '0';
		n /= 10;
	}
	*tmp = n + '0';
	return (num);
}
