/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:15:27 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	frarray(char **array, int ind)
{
	int i;

	i = 0;
	while (i <= ind)
		free(array[i]);
	free(array);
}

static int	countword(char *s, char c)
{
	int count;
	int flag;

	count = 0;
	while (*s)
	{
		flag = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			flag++;
		}
		if (flag)
			count++;
	}
	return (count);
}

static int	*wordsize(char *s, char c, int cw)
{
	int *ws;
	int i;
	int *tmp;

	if (!(ws = ft_memalloc(sizeof(int) * cw)))
		return (NULL);
	tmp = ws;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			i++;
		}
		if (i)
			*tmp++ = i;
	}
	return (ws);
}

static char	**createsplit(char *s, char c, char **split)
{
	int i;
	int k;
	int	*ws;

	ws = wordsize((char *)s, c, countword(s, c));
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			split[k] = ft_strsub(s, i, ws[k] + 1);
			if (!split[k])
			{
				frarray(split, k);
				return (NULL);
			}
			split[k][ws[k]] = '\0';
			i += ws[k++];
		}
	}
	free(ws);
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		cw;

	if (!s)
		return (NULL);
	cw = countword((char *)s, c);
	if (!(split = (char **)ft_memalloc(sizeof(char *) * (cw + 1))))
		return (NULL);
	return (createsplit((char *)s, c, split));
}
