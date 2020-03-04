/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:58:25 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (root)
	{
		if ((*cmpf)(root->item, data_ref) > 0)
			return (btree_search_item(root->left, data_ref, cmpf));
		else if ((*cmpf)(root->item, data_ref) == 0)
			return (root);
		else if ((*cmpf)(root->item, data_ref) < 0)
			return (btree_search_item(root->right, data_ref, cmpf));
	}
	return (0);
}
