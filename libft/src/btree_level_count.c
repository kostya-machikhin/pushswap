/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:59:20 by scuger            #+#    #+#             */
/*   Updated: 2020/01/28 12:59:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		max_value(int arg1, int arg2)
{
	if (arg1 > arg2)
		return (arg1);
	return (arg2);
}

int				btree_level_count(t_btree *root)
{
	if (root && (root->left || root->right))
		return (1 + max_value(btree_level_count(root->right),
						btree_level_count(root->left)));
	else if (root && !root->left && !root->right)
		return (1);
	return (0);
}
