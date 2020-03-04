/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:21 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:21 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_command	*num_command(t_stack *stack_a, t_stack *stack_b)
{
	t_command	*commands;
	t_elem		*cur;
	int			i;

	cur = stack_b->head;
	commands = (t_command *)malloc(sizeof(t_command) * stack_b->size);
	i = 0;
	while (cur)
	{
		command_stack_b(i, stack_b, &commands[i]);
		command_stack_a(cur->index, stack_a, &commands[i]);
		commands[i].same = command_same(commands[i]);
		commands[i].stack_a -= commands[i].same;
		commands[i].stack_b -= commands[i].same;
		commands[i].sum = command_sum(commands[i]);
		cur = cur->next;
		i++;
	}
	return (commands);
}
