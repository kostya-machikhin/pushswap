/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:53:23 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tmp;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	tmp = NULL;
	if (ft_strlen(needle) <= ft_strlen(haystack))
	{
		tmp = (char *)haystack;
		while (*tmp)
		{
			if (!ft_strncmp(tmp, needle, ft_strlen(needle)))
				return (tmp);
			tmp++;
		}
	}
	return (NULL);
}
