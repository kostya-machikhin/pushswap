/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:34:41 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:34:41 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, t_distribution *dist, char name)
{
	t_elem *first;
	t_elem *second;

	if (stack->head && stack->head->next)
	{
		first = stack->head;
		second = stack->head->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		first->prev = second;
		second->next = first;
		second->prev = 0;
		stack->head = second;
		if (stack->size == 2)
			stack->tail = first;
		else if (stack->size == 3)
			stack->tail->prev = first;
		if (name == 'a')
			add_command(dist, 1);
		else if (name == 'b')
			add_command(dist, 2);
	}
}

void	push(t_stack *first_stack, t_stack *second_stack,
		t_distribution *dist, char name)
{
	t_elem *push_elem;

	if (first_stack->size == 0)
		return ;
	push_elem = first_stack->head;
	if (first_stack->head->next)
		first_stack->head->next->prev = 0;
	first_stack->head = first_stack->head->next;
	if (second_stack->head)
		second_stack->head->prev = push_elem;
	else
		second_stack->tail = push_elem;
	push_elem->next = second_stack->head;
	second_stack->head = push_elem;
	second_stack->size++;
	first_stack->size--;
	if (name == 'a')
		add_command(dist, 3);
	else if (name == 'b')
		add_command(dist, 4);
}

void	rotate(t_stack *stack, t_distribution *dist, char name)
{
	t_elem *rotate_elem;

	if (!stack->size || stack->size == 1)
		return ;
	rotate_elem = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = 0;
	add_elem(stack, rotate_elem);
	stack->size--;
	if (name == 'a')
		add_command(dist, 5);
	else if (name == 'b')
		add_command(dist, 6);
}

void	reverse_rotate(t_stack *stack, t_distribution *dist, char name)
{
	t_elem *reverse_elem;

	if (!stack->size || stack->size == 1)
		return ;
	reverse_elem = stack->tail->prev;
	reverse_elem->next = 0;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->tail->prev = 0;
	stack->head = stack->tail;
	stack->tail = reverse_elem;
	if (name == 'a')
		add_command(dist, 7);
	else if (name == 'b')
		add_command(dist, 8);
}
