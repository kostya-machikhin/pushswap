/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:35 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:35 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_first_dist(t_stack *stack)
{
	t_elem	*cur;
	int		count;

	count = 1;
	cur = stack->head;
	while (cur)
	{
		if (!cur->dist)
			break ;
		cur = cur->next;
		count++;
	}
	return (count);
}

int		check_dist(t_stack *stack)
{
	t_elem	*cur;

	cur = stack->head;
	while (cur)
	{
		if (!cur->dist)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	rotate_dist(t_stack *stack, t_distribution *dist,
		void (*f1) (t_stack *, t_distribution *, char),
		void (*f2) (t_stack *, t_distribution *, char))
{
	int before_swap;
	int after_swap;
	int *d;

	d = sn_array(stack);
	before_swap = sum_dist(stack);
	f1(stack, dist, 'a');
	dist->func(stack);
	after_swap = sum_dist(stack);
	if (after_swap <= before_swap)
	{
		f2(stack, dist, 't');
		sn_dist_before(stack, d);
		f1(stack, dist, 't');
	}
	free(d);
}

void	push_b(t_stack *stack, t_distribution *dist)
{
	while (!check_dist(&stack[0]))
	{
		if (swap_needed(&stack[0], dist, 't'))
		{
			swap(&stack[0], dist, 'a');
			dist->func(&stack[0]);
		}
		else if (stack[0].head->dist == FALSE)
			push(&stack[0], &stack[1], dist, 'b');
		else
		{
			if (find_first_dist(&stack[0]) <= stack[0].size / 2)
				rotate_dist(&stack[0], dist, rotate, reverse_rotate);
			else
				rotate_dist(&stack[0], dist, reverse_rotate, rotate);
		}
	}
}
