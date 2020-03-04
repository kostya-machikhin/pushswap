/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_needed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:58 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:58 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sn_dist_before(t_stack *stack, const int *d)
{
	t_elem	*cur;
	int		i;

	i = 0;
	cur = stack->head;
	while (i < stack->size)
	{
		cur->dist = d[i++];
		cur = cur->next;
	}
}

int		sum_dist(t_stack *stack)
{
	t_elem	*cur;
	int		sum;

	sum = 0;
	cur = stack->head;
	while (cur)
	{
		sum += cur->dist;
		cur = cur->next;
	}
	return (sum);
}

int		*sn_array(t_stack *stack)
{
	int		*d;
	int		i;
	t_elem	*cur;

	d = (int *)malloc(sizeof(int) * stack->size);
	cur = stack->head;
	i = 0;
	while (i < stack->size)
	{
		d[i++] = cur->dist;
		cur = cur->next;
	}
	return (d);
}

int		swap_needed(t_stack *stack_a, t_distribution *dist, char name)
{
	int before_swap;
	int after_swap;
	int *d;

	d = sn_array(stack_a);
	before_swap = sum_dist(stack_a);
	swap(stack_a, dist, name);
	dist->func(stack_a);
	after_swap = sum_dist(stack_a);
	swap(stack_a, dist, name);
	sn_dist_before(stack_a, d);
	free(d);
	return (after_swap > before_swap);
}
