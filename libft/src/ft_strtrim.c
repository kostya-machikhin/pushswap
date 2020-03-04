/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:34:18 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcs(char *s, int c)
{
	int		count;
	int		len;

	len = ft_strlen(s);
	count = 0;
	if (c == -1)
	{
		while (*s)
			s++;
		s--;
	}
	while ((*s == ' ' || *s == '\t' || *s == '\n') && len--)
	{
		count++;
		s += c;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	int		count;
	char	*trim;
	char	*tmp;

	tmp = 0;
	count = 0;
	trim = NULL;
	if (s)
	{
		count += ft_strcs((char *)s, 1) + ft_strcs((char *)s, -1);
		count = ft_strlen(s) - count;
		if (count == -(int)ft_strlen(s))
			return (ft_strdup("\0"));
		if (!(trim = ft_strnew(count)))
			return (NULL);
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		tmp = trim;
		while (count--)
			*tmp++ = *s++;
		*tmp = '\0';
	}
	return (trim);
}
