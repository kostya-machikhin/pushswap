/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:31 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:31 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		decryption(t_command command,
		t_stack *stack_a, t_stack *stack_b, t_distribution *dist)
{
	if (command.stack_b > 0)
		while (command.stack_b--)
			rotate(stack_b, dist, 'b');
	else
		while (command.stack_b++)
			reverse_rotate(stack_b, dist, 'b');
	if (command.stack_a > 0)
		while (command.stack_a--)
			rotate(stack_a, dist, 'a');
	else
		while (command.stack_a++)
			reverse_rotate(stack_a, dist, 'a');
	if (command.same > 0)
		while (command.same--)
			rr(stack_a, stack_b, dist);
	else
		while (command.same++)
			rrr(stack_a, stack_b, dist);
}

t_command	find_min_command(t_command *commands, int size)
{
	int			i;
	int			min;
	t_command	command;

	min = commands[0].sum;
	command = commands[0];
	i = 1;
	while (i < size)
	{
		if (min >= commands[i].sum)
		{
			min = commands[i].sum;
			command = commands[i];
		}
		i++;
	}
	return (command);
}

void		push_a(t_stack *stack_a, t_stack *stack_b, t_distribution *dist)
{
	t_command *commands;
	t_command min;

	while (stack_b->head)
	{
		commands = num_command(stack_a, stack_b);
		min = find_min_command(commands, stack_b->size);
		decryption(min, stack_a, stack_b, dist);
		free(commands);
		push(stack_b, stack_a, dist, 'a');
	}
}
