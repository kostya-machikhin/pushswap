/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:49 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:54:59 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_stack *stack_a)
{
	t_elem	*cur;
	int		num;

	num = 0;
	cur = stack_a->head;
	while (cur)
	{
		if (cur->index == 1)
			break ;
		cur = cur->next;
		num++;
	}
	return (num);
}

void	scrolling(t_stack *stack_a, t_distribution *dist)
{
	int rot;

	rot = find_min(stack_a);
	rot = rot <= (stack_a->size / 2) ? rot : rot - stack_a->size;
	if (rot < 0)
	{
		while (rot++)
			reverse_rotate(stack_a, dist, 'a');
	}
	else
	{
		while (rot--)
			rotate(stack_a, dist, 'a');
	}
}
