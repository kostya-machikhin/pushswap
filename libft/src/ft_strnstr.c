/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:00:25 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	if (ft_strlen(needle) <= ft_strlen(haystack))
	{
		tmp = (char *)haystack;
		while (*tmp && i < len)
		{
			if (ft_strlen(needle) <= (len - i))
				if (!ft_strncmp(tmp, needle, ft_strlen(needle)))
					return (tmp);
			tmp++;
			i++;
		}
	}
	return (NULL);
}
