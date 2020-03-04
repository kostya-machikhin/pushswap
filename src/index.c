/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:13 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:13 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_index(t_stack *stack)
{
	t_elem	*min;
	t_elem	*cur;
	int		i;

	i = -1;
	while (++i < stack->size)
	{
		min = 0;
		cur = stack->head;
		while (cur)
		{
			if ((!min || min->num > cur->num) && !cur->index)
			{
				min = cur;
			}
			cur = cur->next;
		}
		min->index = i + 1;
	}
}
