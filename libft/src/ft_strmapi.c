/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:31:33 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	int		i;

	i = 0;
	ns = NULL;
	if (s && f)
	{
		if (!(ns = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			ns[i] = f(i, s[i]);
			i++;
		}
	}
	return (ns);
}
