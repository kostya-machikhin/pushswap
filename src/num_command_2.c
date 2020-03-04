/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_command_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:26 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:26 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			command_sum(t_command command)
{
	int a;
	int b;
	int c;

	a = (command.stack_a > 0 ? command.stack_a : -command.stack_a);
	b = (command.stack_b > 0 ? command.stack_b : -command.stack_b);
	c = (command.same > 0 ? command.same : -command.same);
	return (a + b + c);
}

int			command_same(t_command command)
{
	if (command.stack_a > 0 && command.stack_b > 0)
		return (command.stack_a < command.stack_b
				? command.stack_a : command.stack_b);
	else if (command.stack_a < 0 && command.stack_b < 0)
		return (command.stack_a > command.stack_b
				? command.stack_a : command.stack_b);
	else
		return (0);
}

int			max_stack_a(t_stack *stack)
{
	int		i;
	t_elem	*cur;
	int		max;
	int		num;

	num = 0;
	max = 0;
	cur = stack->head;
	i = 1;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			num = i;
		}
		cur = cur->next;
		i++;
	}
	return (num);
}

void		command_stack_a(int index, t_stack *stack_a, t_command *command)
{
	int		i;
	t_elem	*cur;
	int		max;
	int		num;

	num = max_stack_a(stack_a);
	max = 0;
	cur = stack_a->head;
	i = 1;
	while (cur)
	{
		if (cur->index > max)
		{
			if (max && cur->index > index)
				break ;
			else if (cur->index < index)
			{
				max = cur->index;
				num = i;
			}
		}
		cur = cur->next;
		i++;
	}
	command->stack_a = num <= stack_a->size / 2 ? num : num - stack_a->size;
}

void		command_stack_b(int i, t_stack *stack_b, t_command *command)
{
	if (i <= stack_b->size / 2)
		command->stack_b = i;
	else
		command->stack_b = i - stack_b->size;
}
