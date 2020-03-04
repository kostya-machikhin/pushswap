/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:51:02 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;

	cat = NULL;
	if (s1 && s2)
	{
		if (ft_strlen(s1) + ft_strlen(s2) < ft_strlen(s1) ||
				ft_strlen(s1) + ft_strlen(s2) < ft_strlen(s2))
			return (NULL);
		if ((cat = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcat(cat, (char *)s1);
			ft_strcat(cat, (char *)s2);
		}
	}
	else if (s1)
	{
		if ((cat = ft_strnew(ft_strlen(s1))))
			ft_strcat(cat, (char *)s1);
	}
	else if (s2)
	{
		if ((cat = ft_strnew(ft_strlen(s2))))
			ft_strcat(cat, (char *)s2);
	}
	return (cat);
}
