/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:10:56 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char **str)
{
	int		i;
	char	*s;
	char	*tmp;

	tmp = 0;
	i = 0;
	while (str[0][i] != '\n' && str[0][i])
		i++;
	s = ft_strsub(*str, 0, i);
	i += (*(*str + i) == '\0' ? 0 : 1);
	tmp = ft_strdup(*str + i);
	free(*str);
	*str = tmp;
	if (**str == '\0')
	{
		free(*str);
		*str = 0;
	}
	return (s);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[10239];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmpstr;

	ret = 0;
	if (fd >= 0 && line)
	{
		if (!(str[fd] && ft_strchr(str[fd], '\n')))
			while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
			{
				buf[ret] = '\0';
				tmpstr = ft_strjoin(str[fd], buf);
				free(str[fd]);
				str[fd] = tmpstr;
				if (ft_strchr(buf, '\n'))
					break ;
			}
	}
	if (fd < 0 || ret < 0 || !line)
		return (-1);
	else if (!str[fd] || !*str[fd])
		return (0);
	*line = get_line(&str[fd]);
	return (1);
}
