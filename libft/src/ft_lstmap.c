/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:59:51 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	frlst(t_list **lst)
{
	if (lst && *lst)
	{
		if ((*lst)->next)
			frlst(&(*lst)->next);
		free(lst);
		lst = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *tmp;
	t_list *ln;

	if (!(ln = f(lst)))
		return (NULL);
	if (!(list = ft_lstnew(ln->content, ln->content_size)))
		return (NULL);
	tmp = list;
	while (lst->next)
	{
		if (!(ln = f(lst->next)))
			return (NULL);
		if (!(list->next = ft_lstnew(ln->content,
						ln->content_size)))
		{
			frlst(&tmp);
			return (NULL);
		}
		lst = lst->next;
		list = list->next;
	}
	return (tmp);
}
