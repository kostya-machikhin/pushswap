/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:54 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:54 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_elem *cur;
	t_elem *tmp;

	cur = 0;
	tmp = 0;
	if (stack)
	{
		cur = stack->head;
		while (cur)
		{
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
	}
}

t_elem	*newelem(long long data)
{
	t_elem *elem;

	elem = (t_elem *)ft_memalloc(sizeof(t_elem));
	elem->num = data;
	elem->index = 0;
	elem->next = 0;
	elem->prev = 0;
	return (elem);
}

t_stack	*add_elem(t_stack *stack, t_elem *newelem)
{
	newelem->prev = stack->tail;
	newelem->next = 0;
	if (!stack->head)
	{
		stack->head = newelem;
		stack->tail = stack->head;
	}
	else
	{
		stack->tail->next = newelem;
		stack->tail = stack->tail->next;
	}
	stack->size++;
	return (stack);
}

t_stack	create_stack(void)
{
	t_stack stack;

	stack.size = 0;
	stack.head = 0;
	stack.tail = 0;
	return (stack);
}
