/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:34:51 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:34:51 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_command(t_distribution *dist, int command)
{
	int *tmp;
	int i;

	i = -1;
	tmp = 0;
	if (dist)
	{
		tmp = (int *)ft_memalloc(sizeof(int) * (dist->size + 1));
		while (++i < dist->size)
			tmp[i] = dist->dist[i];
		tmp[dist->size++] = command;
		free(dist->dist);
		dist->dist = tmp;
	}
}

void	clean_dist(t_stack *stack)
{
	t_elem *cur;

	cur = stack->head;
	while (cur)
	{
		cur->dist = FALSE;
		cur = cur->next;
	}
}

void	distribution_one(t_stack *stack)
{
	int		index;
	t_elem	*cur;

	clean_dist(stack);
	cur = stack->head;
	index = stack->head->index;
	while (cur)
	{
		if (cur->index == index)
		{
			cur->dist = TRUE;
			index++;
		}
		else
			cur->dist = FALSE;
		cur = cur->next;
	}
}

void	distribution_two(t_stack *stack)
{
	t_elem	*cur;
	t_elem	*next;

	cur = stack->head;
	next = cur->next;
	cur->dist = 1;
	while (next)
	{
		next->dist = next->num > cur->num ? 1 : 0;
		if (next->dist)
			cur = next;
		next = next->next;
	}
}
